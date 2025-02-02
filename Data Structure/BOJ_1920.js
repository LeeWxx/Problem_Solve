/*
BOJ 1920 수 찾기

1. M개의 수를 전부 A안에 존재하는지 선형 순회할 경우 O(N*N)
2. 입력 사이즈가 100,000이므로, 이진 탐색으로 O(N * logN)으로 단축
*/

fs = require("fs");
const filePath = process.platform === "linux" ? "dev/stdin" : "run/input.txt";
const input = fs.readFileSync(filePath).toString().trim().split('\n')

const binarySearch = (arr, target) => {
    let start = 0;
    let end = arr.length - 1

    while (start <= end) {

        let mid = Math.floor((start + end) / 2)
        
        if (arr[mid] === target)
            return 1;

        if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1
    }

    return 0;
}

const result = [];

const arr = input[1].split(' ').map(v => parseInt(v))
arr.sort((a,b)=>a-b)

const target_arr = input[3].split(' ').map(v => parseInt(v))

target_arr.map(v => {
    result.push(binarySearch(arr, v))
})

result.map(v => console.log(v)) 
