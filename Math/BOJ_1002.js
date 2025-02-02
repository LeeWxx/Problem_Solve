/*
BOJ 1002 터렛

1. 터렛 좌표를 기준으로 원의 방정식을 구할 수 있다.
2. 조규현의 원과 백승화의 원의 교점 개수를 구한다.
3. 중심 좌표 및 반지름이 일치하면 교점의 개수는 무한대이다. 
*/

fs = require("fs");
const filePath = process.platform === "linux" ? "dev/stdin" : "run/input.txt";
const input = fs.readFileSync(filePath).toString().trim().split('\n')

const T = parseInt(input[0])

for (let i=1; i<=T; i++)
{
    const newArr = input[i].split(' ').map(item => parseInt(item))

    const first_x = newArr[0]
    const first_y = newArr[1]
    const first_r = newArr[2]

    const second_x = newArr[3]
    const second_y = newArr[4]
    const second_r = newArr[5]

    const d = Math.sqrt(Math.pow((second_x -first_x), 2) + Math.pow((second_y -first_y), 2))

    const radiusDiff = Math.abs(first_r - second_r)
    const radiusSum = Math.abs(first_r + second_r)

    if(d === 0 && first_r === second_r)
        console.log(-1)
    else if(d < radiusDiff || d > radiusSum)
        console.log(0)
    else if(d === radiusDiff || d === radiusSum)
        console.log(1)
    else if(radiusDiff < d && d < radiusSum)
        console.log(2)
}