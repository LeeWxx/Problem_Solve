/*
BOJ 11866 요세푸스 문제 0
*/

fs = require("fs");
const filePath = process.platform === "linux" ? "dev/stdin" : "run/input.txt";
const input = fs.readFileSync(filePath).toString().trim()

class Queue {
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
        if (this.isEmpty())
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

    peek() {
        if (this.isEmpty())
            return -1;

        return this.items[this.frontIndex]
    }
}

const [N, K] = input.split(' ').map(Number);

let result = '<';
const queue = new Queue();

const arr = Array.from({ length: N }, (_, i) => i + 1)
arr.map((item) => queue.enqueue(item))

let cnt = 0
while (queue.size() > 1) {
    const item = queue.dequeue();
    cnt++;

    if (cnt === K) {
        result += (item + ', ')
        cnt = 0;
    }

    else {
        queue.enqueue(item)
    }
}


result += queue.dequeue() + '>'

console.log(result)
