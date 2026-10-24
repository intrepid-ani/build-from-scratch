#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, int start, int end, int mid)
{
    int i = start, j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= end)
    {
        if (nums[i] < nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(nums[j]);
        j++;
    }

    for (int i = start; i <= end; i++)
    {
        nums[i] = temp[i - start];
    }
}

void mergeSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);

    merge(nums, start, end, mid);
}
int main()
{
    int size;
    vector<int> nums;
    cout << "Enter size of an array: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        nums.push_back(0);
        cout << "Enter element for index [" << i << "]: ";
        cin >> nums[i];
    }

    mergeSort(nums, 0, size - 1);

    cout
        << endl
        << endl;

    for (int i : nums)
    {
        cout << i << ", ";
    }
}
