/*
BOJ 7569 토마토

1. 각 칸이 익는데 걸리는 최소 시간 => BFS로 접근
2. 입력에서 주어진 익은 토마토의 위치를 큐에 삽입
3. 큐의 크기가 0이 될 때 까지 큐에 있는 요소를 빼낸 뒤, 근처 탐색
4. 이 때 0인 칸은 1로, 1인 칸은 방문 여부를 체크하고 큐에 삽입
*/

fs = require("fs");
const filePath = process.platform === "linux" ? "dev/stdin" : "run/input.txt";
const input = fs.readFileSync(filePath).toString().trim().split('\n')

const D_POS = [[1, 0, 0], [-1, 0, 0], [0, 1, 0], [0, -1, 0], [0, 0, 1], [0, 0, -1]]

class Queue {
    constructor() {
        this.items = {}
        this.frontIndex = 0;
        this.backIndex = 0;
    }

    enqueue(item) {
        this.items[this.backIndex] = item
        this.backIndex++;
    }

    dequeue() {
        if (this.isEmpty())
            return -1;

        const item = this.items[this.frontIndex]
        this.frontIndex++;
        return item;
    }

    isEmpty() {
        return this.frontIndex === this.backIndex
    }

    size() {
        return this.backIndex - this.frontIndex
    }
}

const check = (box) => {
    return !box.some(plane => plane.some(row => row.includes(0)));
}

const bfs = (box, queue) => {
    let day = 0;
    while (!queue.isEmpty()) {

        if (check(box))
            break;

        const size = queue.size();


        for (let i = 0; i < size; i++) {
            const [z, y, x] = queue.dequeue()

            for (let i = 0; i < D_POS.length; i++) {

                const [_z, _y, _x] = [z + D_POS[i][0], y + D_POS[i][1], x + D_POS[i][2]]

                if (_z < 0 || _z >= H ||
                    _y < 0 || _y >= N ||
                    _x < 0 || _x >= M)
                    continue;


                if (box[_z][_y][_x] !== 0)
                    continue;

                queue.enqueue([_z, _y, _x])
                box[_z][_y][_x] = 1
            }
        }
        day++;
    }

    return day;
}

const [M, N, H] = input.shift().split(' ').map(Number)

const box = Array.from(new Array(H), () => (
    Array.from(new Array(N), () => (
        new Array(M).fill(0)
    ))
))

const arr = input.map((item) => item.split(' ').map(Number))


const queue = new Queue();

for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr[i].length; j++) {
        const z = parseInt(i / N);
        const y = i % N;
        const x = j;

        box[z][y][x] = arr[i][j]

        if (box[z][y][x] === 1)
            queue.enqueue([z, y, x]);
    }
}

const day = bfs(box, queue);

if (check(box))
    console.log(day)
else
    console.log(-1)