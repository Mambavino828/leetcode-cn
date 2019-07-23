﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;


//int lowerBound(vector<int> &nums, int x, int low, int high)
//{
//	if (low >= high) return low;
//	int mid = low + (high - low) / 2;
//	if (nums[mid] < x) return lowerBound(nums, x, mid + 1, high);
//	else return lowerBound(nums, x, low, mid);
//}

//int lowerBound(vector<int> &nums, int x, int low, int high)
//{
//	while (low < high)
//	{
//		int mid = low + (high - low) / 2;
//		if (nums[mid] < x) low = mid + 1;
//		else high = mid;
//	}
//	return low;
//}


vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
	int low = 0;
	int high = arr.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] < x) low = mid + 1;
		else high = mid;
	}
	int mid = low;
	while (high - low < k)
	{
		if (k > arr.size()) return {};
		if (low == 0)
		{
			high = high + 1;
			continue;
		}
		else if (high == arr.size())
		{
			low = low - 1;
			continue;
		}

		if (x - arr[low - 1] <= arr[high] - x) low = low - 1;
		else high = high + 1;
	}
	vector<int> res;
	res.assign(&arr[low], &arr[high]);
	return res;
}

int main()
{
	vector<string> str;
	vector<int> k;
	vector<int> x;
	vector<vector<int>> answer;
	str.push_back("[1,2,3,4,5]");
	k.push_back(4);
	x.push_back(3);
	answer.push_back({ 1,2,3,4 });

	str.push_back("[1,2,3,4,5]");
	k.push_back(4);
	x.push_back(-1);
	answer.push_back({ 1,2,3,4 });

	for (int i = 0; i < str.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		vector<int> nums = StringToVectorInt(str[i]);
		printVectorInt(nums);
		cout << "k = " << k[i] << ", x = " << x[i] << endl;
		vector<int> n = findClosestElements(nums, k[i], x[i]);
		printVectorInt(n);
		cout << "Answer = ";
		printVectorInt(answer[i]);
	}
}
