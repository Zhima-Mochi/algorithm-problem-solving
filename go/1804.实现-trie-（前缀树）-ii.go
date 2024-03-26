package main

type TrieNode struct {
	cnt       int
	prefixCnt int
	branches  [26]*TrieNode
}

type Trie struct {
	root *TrieNode
}

func Constructor() Trie {
	return Trie{root: &TrieNode{}}
}

func (this *Trie) Insert(word string) {
	cur := this.root
	for _, c := range word {
		pos := c - 'a'
		if cur.branches[pos] == nil {
			cur.branches[pos] = &TrieNode{}
		}
		cur = cur.branches[pos]
		cur.prefixCnt++
	}
	cur.cnt++
}

func (this *Trie) toNode(word string) *TrieNode {
	cur := this.root
	for _, c := range word {
		pos := c - 'a'
		if cur.branches[pos] == nil {
			return nil
		}
		cur = cur.branches[pos]
	}
	return cur
}

func (this *Trie) CountWordsEqualTo(word string) int {
	node := this.toNode(word)
	if node == nil {
		return 0
	}
	return node.cnt
}

func (this *Trie) CountWordsStartingWith(prefix string) int {
	node := this.toNode(prefix)
	if node == nil {
		return 0
	}
	return node.prefixCnt
}

func (this *Trie) Erase(word string) {
	if node := this.toNode(word); node == nil {
		return
	}
	cur := this.root
	for _, c := range word {
		pos := c - 'a'
		cur = cur.branches[pos]
		cur.prefixCnt--
	}
	cur.cnt--
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.CountWordsEqualTo(word);
 * param_3 := obj.CountWordsStartingWith(prefix);
 * obj.Erase(word);
 */
