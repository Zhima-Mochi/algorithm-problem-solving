#
# @lc app=leetcode id=2353 lang=python3
#
# [2353] Design a Food Rating System
#

# @lc code=start
from sortedcontainers import SortedSet
from collections import defaultdict

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.cuisineFoods = defaultdict(SortedSet)
        self.foodRates = defaultdict(int)
        self.foodCuisine = defaultdict(str)
        n = len(foods)
        for i in range(n):
            self.cuisineFoods[cuisines[i]].add((-ratings[i],foods[i]))
            self.foodRates[foods[i]] = -ratings[i]
            self.foodCuisine[foods[i]] = cuisines[i]

    def changeRating(self, food: str, newRating: int) -> None:
        self.cuisineFoods[self.foodCuisine[food]].remove((self.foodRates[food],food))
        self.cuisineFoods[self.foodCuisine[food]].add((-newRating,food))
        self.foodRates[food] = -newRating

    def highestRated(self, cuisine: str) -> str:
        return self.cuisineFoods[cuisine][0][1]

# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
# @lc code=end
