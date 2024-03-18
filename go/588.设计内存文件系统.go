package main

import (
	"errors"
	"sort"
	"strings"
)

type AbstractFile interface {
	GetName() string
	Add(abstractFile AbstractFile) error
	AddContent(content string) error
	ReadContent() (string, error)
	Search(name string) (AbstractFile, error)
}

type File struct {
	Name    string
	Content string
}

func (f *File) GetName() string {
	return f.Name
}

func (f *File) Add(abstractFile AbstractFile) error {
	return errors.New("file cannot add file")
}

func (f *File) AddContent(content string) error {
	f.Content += content
	return nil
}

func (f *File) ReadContent() (string, error) {
	return f.Content, nil
}

func (f *File) Search(name string) (AbstractFile, error) {
	return nil, errors.New("file cannot search")
}

type Folder struct {
	Name  string
	Files []AbstractFile
}

func (f *Folder) GetName() string {
	return f.Name
}

func (f *Folder) Add(abstractFile AbstractFile) error {
	f.Files = append(f.Files, abstractFile)
	return nil
}

func (f *Folder) AddContent(content string) error {
	return errors.New("folder cannot add content")
}

func (f *Folder) ReadContent() (string, error) {
	return "", errors.New("folder cannot read content")
}

func (f *Folder) Search(name string) (AbstractFile, error) {
	for _, file := range f.Files {
		if file.GetName() == name {
			return file, nil
		}
	}
	return nil, errors.New("file not found")
}

type FileSystem struct {
	Root AbstractFile
}

func Constructor() FileSystem {
	return FileSystem{
		Root: &Folder{
			Name:  "",
			Files: make([]AbstractFile, 0),
		},
	}
}

func (this *FileSystem) Ls(path string) []string {
	paths := strings.Split(path, "/")
	if paths[len(paths)-1] == "" {
		paths = paths[:len(paths)-1]
	}

	current := this.Root

	for _, path := range paths {
		next, err := current.Search(path)
		if err != nil {
			return []string{}
		}
		current = next
	}

	if _, ok := current.(*File); ok {
		return []string{current.GetName()}
	}

	files := current.(*Folder).Files
	names := make([]string, 0)
	for _, file := range files {
		names = append(names, file.GetName())
	}

	sort.Strings(names)

	return names
}

func (this *FileSystem) Mkdir(path string) {
	paths := strings.Split(path, "/")
	current := this.Root
	for _, p := range paths {
		file, err := current.Search(p)
		if err != nil {
			f := &Folder{
				Name:  p,
				Files: make([]AbstractFile, 0),
			}
			current.Add(f)
			current = f
		} else {
			current = file
		}
	}
}

func (this *FileSystem) AddContentToFile(filePath string, content string) {
	paths := strings.Split(filePath, "/")
	current := this.Root
	for _, p := range paths[:len(paths)-1] {
		file, err := current.Search(p)
		if err != nil {
			f := &Folder{
				Name: p,
			}
			current.Add(f)
			current = f
		} else {
			current = file
		}
	}

	if file, err := current.Search(paths[len(paths)-1]); err != nil {
		f := &File{
			Name:    paths[len(paths)-1],
			Content: content,
		}
		current.Add(f)
	} else {
		file.AddContent(content)
	}
}

func (this *FileSystem) ReadContentFromFile(filePath string) string {
	paths := strings.Split(filePath, "/")
	current := this.Root
	for _, p := range paths[:len(paths)-1] {
		file, err := current.Search(p)
		if err != nil {
			return ""
		}
		current = file
	}

	if file, err := current.Search(paths[len(paths)-1]); err != nil {
		return ""
	} else {
		content, _ := file.ReadContent()
		return content
	}
}

/**
 * Your FileSystem object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ls(path);
 * obj.Mkdir(path);
 * obj.AddContentToFile(filePath,content);
 * param_4 := obj.ReadContentFromFile(filePath);
 */
