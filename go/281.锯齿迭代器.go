package main

type Iterator struct {
	arr    []int
	cursor int
	size   int
}

func NewIterator(arr []int) *Iterator {
	return &Iterator{
		arr:    arr,
		cursor: 0,
		size:   len(arr),
	}
}

func (i *Iterator) next() int {
	if !i.hasNext() {
		return 0
	}
	i.cursor++
	return i.arr[i.cursor-1]
}

func (i *Iterator) hasNext() bool {
	return i.cursor != i.size
}

type ZigzagIterator struct {
	i1   *Iterator
	i2   *Iterator
	flag bool
}

func Constructor(v1, v2 []int) *ZigzagIterator {
	zi := &ZigzagIterator{
		i1:   NewIterator(v1),
		i2:   NewIterator(v2),
		flag: true,
	}
	if !zi.i1.hasNext() {
		zi.flag = false
	}
	return zi
}

func (this *ZigzagIterator) next() int {
	var val int
	if this.flag {
		val = this.i1.next()
		if this.i2.hasNext() {
			this.flag = false
		}
	} else {
		val = this.i2.next()
		if this.i1.hasNext() {
			this.flag = true
		}
	}
	return val
}

func (this *ZigzagIterator) hasNext() bool {
	return this.i1.hasNext() || this.i2.hasNext()
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * obj := Constructor(param_1, param_2);
 * for obj.hasNext() {
 *	 ans = append(ans, obj.next())
 * }
 */
