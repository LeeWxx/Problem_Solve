/*
BOJ 2164 카드2

1. 선입선출의 개념으로 큐를 사용
2. JS에서 큐를 배열로 구현할 경우 dequeue, 즉 shift 연산이 O(N)의 시간복잡도
3. 이를 개선하기 위해 객체에 배열 인덱스를 적용
*/

fs = require("fs");
const filePath = process.platform === "linux" ? "dev/stdin" : "run/input.txt";
const input = fs.readFileSync(filePath).toString().trim()

class Queue{
    constructor() {
        this.items = {};
        this.frontIndex = 0;
        this.backIndex = 0;
    }

    enqueue(element) {
        this.items[this.backIndex] = element;
        this.backIndex++;
    }

    dequeue() {
        if(this.isEmpty())
            return -1;

        const item = this.items[this.frontIndex];
        this.frontIndex++;
        return item
    }

    isEmpty() {
        return this.frontIndex === this.backIndex
    }

    size() {
        return this.backIndex - this.frontIndex;
    }

    peek(){
        if(this.isEmpty())
            return -1;

        return this.items[this.frontIndex]
    }
}

const arr = Array.from({length: Number(input)}, (_, i) => i+1)

const queue = new Queue();

arr.map((item)=> {
    queue.enqueue(item)
})

while(queue.size() > 1){
    queue.dequeue();
    const item = queue.dequeue();
    queue.enqueue(item);
}


console.log(queue.peek())