/*
 * @lc app=leetcode id=2096 lang=golang
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
 */
package main

import "strings"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func getDirections(root *TreeNode, startValue int, destValue int) string {
	getParent := map[int]*TreeNode{}
	getDepth := map[int]int{}
	stk := []*TreeNode{}
	cur := root
	depth := 0
	for cur != nil || len(stk) > 0 {
		if cur == nil {
			cur = stk[len(stk)-1]
			depth = getDepth[cur.Val]
			if cur.Right != nil {
				getParent[cur.Right.Val] = cur
			}
			cur = cur.Right
			stk = stk[:len(stk)-1]
			depth += 1
		} else {
			getDepth[cur.Val] = depth
			if cur.Left != nil {
				getParent[cur.Left.Val] = cur
			}
			stk = append(stk, cur)
			cur = cur.Left
			depth += 1
		}
	}
	road := []string{}
	upCnt := 0
	for startValue != destValue {
		if getDepth[startValue] <= getDepth[destValue] {
			next := getParent[destValue]
			if next.Left != nil && next.Left.Val == destValue {
				road = append(road, "L")
			} else {
				road = append(road, "R")
			}
			destValue = next.Val
		} else if getDepth[startValue] > getDepth[destValue] {
			next := getParent[startValue]
			upCnt += 1
			startValue = next.Val
		}
	}

	ans := []string{}
	for upCnt > 0 {
		ans = append(ans, "U")
		upCnt -= 1
	}
	l := len(road)
	for i := l - 1; i != -1; i-- {
		ans = append(ans, road[i])
	}
	return strings.Join(ans, "")
}

// @lc code=end
