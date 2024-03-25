package main

import "sort"

type Trie struct {
	sentences []string
	branches  [256]*Trie
}

func NewTrie() *Trie {
	return &Trie{
		sentences: []string{},
	}
}

type AutocompleteSystem struct {
	sentences []string
	strTimes  map[string]int
	root      *Trie
	cursor    *Trie
	sentence  []byte
}

func (a *AutocompleteSystem) Insert(sentence string, t int) {
	if t == -1 {
		a.strTimes[sentence]++
	} else {
		a.strTimes[sentence] = t
	}
	cur := a.root
	for _, c := range sentence {
		pos := c
		if cur.branches[pos] == nil {
			cur.branches[pos] = NewTrie()
		}
		cur = cur.branches[pos]
		if a.strTimes[sentence] == 1 || t != -1 {
			cur.sentences = append(cur.sentences, sentence)
		}
		sort.Slice(cur.sentences, func(i, j int) bool {
			if a.strTimes[cur.sentences[i]] > a.strTimes[cur.sentences[j]] {
				return true
			}

			if a.strTimes[cur.sentences[i]] < a.strTimes[cur.sentences[j]] {
				return false
			}
			return cur.sentences[i] < cur.sentences[j]
		})
	}
}

func Constructor(sentences []string, times []int) AutocompleteSystem {
	ret := AutocompleteSystem{sentences: sentences, root: NewTrie(), strTimes: map[string]int{}, sentence: []byte{}}
	ret.cursor = ret.root
	for i, sentence := range sentences {
		ret.Insert(sentence, times[i])
	}

	return ret
}

func (this *AutocompleteSystem) Input(c byte) []string {
	ans := []string{}
	if c == '#' {
		this.cursor = this.root
		this.Insert(string(this.sentence), -1)
		this.sentence = []byte{}
		return ans
	}
	this.sentence = append(this.sentence, c)
	pos := c
	if this.cursor != nil {
		this.cursor = this.cursor.branches[pos]
	}
	if this.cursor != nil {
		if len(this.cursor.sentences) > 3 {
			ans = this.cursor.sentences[:3]
		} else {
			ans = this.cursor.sentences
		}
	}

	return ans
}

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * obj := Constructor(sentences, times);
 * param_1 := obj.Input(c);
 */
