/*
BOJ 23291 어항 정리

1. 물고기의 수가 가장 적은 어항들에 물고리를 한 마리 넣는다.
2. 가장 왼쪽 어항을 그 오른쪽 어항 위에 올린다.
3. 첫번째 어항 정리를 진행한다.
4. 어항에 있는 물고기 수를 조절한다.
5. 두번째 어항 정리를 진행한다.
6. 어항에 있는 물고기 수를 조절한다.
*/

fs = require("fs");
const filePath = process.platform === "linux" ? "dev/stdin" : "run/input.txt";
const input = fs.readFileSync(filePath).toString().trim().split('\n')

const MAX_FISH_CNT = 10000;

const checkTanks = (arr) => {
    maxFishCnt = 0
    minFishCnt = MAX_FISH_CNT

    for (let i = 0; i < arr.length; i++) {
        
        if(arr[i][0] > maxFishCnt)
            maxFishCnt = arr[i][0]

        if(arr[i][0] < minFishCnt)
            minFishCnt = arr[i][0]
    }

    if (maxFishCnt - minFishCnt > K)
        return false;
    else
        return true
}

const fillTanks = (arr) => {
    let minFishCnt = MAX_FISH_CNT;
    let idxArr = [];

    for (let i = 0; i < arr.length; i++) {
        if (minFishCnt > arr[i][0]) {
            minFishCnt = arr[i][0]
            idxArr.length = 0;
            idxArr.push(i)
        }
        else if (minFishCnt === arr[i][0]) {
            idxArr.push(i)
        }
    }

    for (let i = 0; i < idxArr.length; i++) {
        const idx = idxArr[i]
        arr[idx][0]++
    }
}

const flatternTanks = (arr) => {
    let newArr = [];

    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr[i].length; j++) {
            newArr.push([arr[i][j]])
        }
    }

    return newArr
}


const adjustTanks = (arr) => {
    const resultArr = arr.map(row => row.slice())

    for (let i = 0; i < arr.length; i++) {
        const len = arr[i].length

        for (let j = 0; j < len; j++) {
            if (j < len - 1) {
                const a = arr[i][j]
                const b = arr[i][j + 1]

                const d = parseInt((a - b) / 5)

                if (Math.abs(d) > 0) {
                    resultArr[i][j] -= d
                    resultArr[i][j + 1] += d
                }
            }

            if (i + 1 < arr.length && arr[i + 1].length > j) {
                const a = arr[i][j]
                const b = arr[i + 1][j]

                const d = parseInt((a - b) / 5)

                if (Math.abs(d) > 0) {
                    resultArr[i][j] -= d
                    resultArr[i + 1][j] += d
                }
            }
        }
    }

    return flatternTanks(resultArr)

}

const firstOrganize = (arr) => {
    while (true) {
        let startIdx = 0;
        for (let i = 0; i < arr.length; i++) {
            if (arr[i].length !== 0)
                break;

            startIdx++;
        }

        let n = 0;
        for (let i = startIdx; i < arr.length; i++) {
            if (arr[i].length < 2)
                break;

            n++
        }

        //옮겨야 할 어항의 개수 높이와 바닥에 있는 어항 개수 비교
        if (arr[startIdx].length > arr.length - (startIdx + n))
            break


        const height = arr[startIdx].length
        const floorStartIdx = startIdx + n

        for (let i = 0; i < height; i++) {
            for (let j = startIdx + n - 1; j >= startIdx; j--)
                arr[i + floorStartIdx].push(arr[j].shift())
        }
    }
}

const secondOrganize = (arr) => {

    let startIdx = 0
    for (let i = 1; i <= 2; i++) {
        const n = N / (2 * i)
        startIdx += n;
        for (let j = 0; j < n; j++) {
            for (let k = 0; k <= arr[startIdx - 1 - j].length; k++)
                arr[startIdx + j].push(arr[startIdx - 1 - j].pop())
        }
    }
}


const [N, K] = input[0].split(' ')

const arr = input[1].split(' ')
let fishTanks = arr.map(item => [Number(item)]);

let count = 0;

while (!checkTanks(fishTanks)) {
    // 물고기 수 보충
    fillTanks(fishTanks)

    // 가장 왼쪽 어항을 오른쪽 어항으로 이동
    fishTanks[1].push(fishTanks[0][0])
    fishTanks[0].pop()

    // 첫번째 어항 정리
    firstOrganize(fishTanks)
    fishTanks = adjustTanks(fishTanks)

    // 두번째 어항 정리
    secondOrganize(fishTanks)
    fishTanks = adjustTanks(fishTanks)

    count++;
}

console.log(count)