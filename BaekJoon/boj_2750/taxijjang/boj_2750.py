import sys

n = int(input())

arr=[]

def bubble_sort():
    for i in range(0 , n):
        for j in range(0,n-(i+1)):
            if arr[j] > arr[j+1]:
               tmp = arr[j+1]
               arr[j+1] = arr[j]
               arr[j] = tmp;
            
for _ in range(n):
    arr.append(int(sys.stdin.readline()))

bubble_sort()

for i in arr:
    print(i)
