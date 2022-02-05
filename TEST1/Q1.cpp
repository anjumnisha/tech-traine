/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7   */
 #include<iostream>
 using namespace std;
 int main()
 {
    int n;
    cout<<"Enter size of array :";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int k;
    cout<<"Enter value of k :";
    cin>>k;
    int ans[n-k+1];
    int max;

    for(int i=0;i<(n-k+1);i++)
    {
        max=arr[i];
        for(int j=i+1;j<i+k;j++)
        {
            if(max<arr[j])
            {
             max=arr[j];
            }
        }
        ans[i]=max;
    }

    for(int i=0;i<(n-k+1);i++)
        cout<<ans[i]<<" ";

    return 0;
 }
