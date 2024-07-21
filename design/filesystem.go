package main

import (
	"container/list"
	"errors"
	"fmt"
)

var (
	ErrNotSupport = errors.New("not support")

	ErrNotFound = errors.New("not found")
)

type FileComponent interface {
	GetName() string
	AddFile(file FileComponent) error
	RemoveFile(file FileComponent) error
	SearchFile(name string) (FileComponent, error)
}

type AbstractFileLeaf struct {
	content string
	name    string
}

func (l *AbstractFileLeaf) GetName() string {
	return l.name
}

func (l *AbstractFileLeaf) AddFile(file FileComponent) error {
	return ErrNotSupport
}

func (l *AbstractFileLeaf) RemoveFile(file FileComponent) error {
	return ErrNotSupport
}

func (l *AbstractFileLeaf) SearchFile(name string) (FileComponent, error) {
	return nil, ErrNotSupport
}

func (l *AbstractFileLeaf) WriteContent(content string) error {
	l.content = content
	return nil
}

func (l *AbstractFileLeaf) ReadContent() (string, error) {
	return l.content, nil
}

type AbstractFileNode struct {
	name     string
	children *list.List
}

func (n *AbstractFileNode) GetName() string {
	return n.name
}

func (n *AbstractFileNode) AddFile(file FileComponent) error {
	n.children.PushBack(file)
	return nil
}

func (n *AbstractFileNode) RemoveFile(file FileComponent) error {
	for e := n.children.Front(); e != nil; e = e.Next() {
		if e.Value == file {
			n.children.Remove(e)
			return nil
		}
	}
	return nil
}

func (n *AbstractFileNode) SearchFile(name string) (FileComponent, error) {
	for e := n.children.Front(); e != nil; e = e.Next() {
		if f := e.Value.(FileComponent); f.GetName() == name {
			return f, nil
		}
	}
	return nil, ErrNotFound
}

type TextFile struct {
	AbstractFileLeaf
}

type Folder struct {
	AbstractFileNode
}

func main() {
	root := &Folder{
		AbstractFileNode: AbstractFileNode{
			name:     "",
			children: list.New(),
		},
	}

	tf := &TextFile{
		AbstractFileLeaf: AbstractFileLeaf{
			name: "text.txt",
		},
	}

	root.AddFile(tf)

	if f, e := root.SearchFile("text.txt"); e == nil {
		fmt.Println(f.GetName())
	}

	if _, e := root.SearchFile("text2.txt"); e != nil {
		fmt.Println(e)
	}

	tf2 := &TextFile{
		AbstractFileLeaf: AbstractFileLeaf{
			name: "text2.txt",
		},
	}

	root.AddFile(tf2)

	if f, e := root.SearchFile("text2.txt"); e == nil {
		fmt.Println(f.GetName())
	}

	root.RemoveFile(tf)

	if _, e := root.SearchFile("text.txt"); e != nil {
		fmt.Println(e)
	}

	if f, e := root.SearchFile("text2.txt"); e == nil {
		fmt.Println(f.GetName())
	}
}
