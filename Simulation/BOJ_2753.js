fs = require("fs");
const filePath = process.platform === "linux" ? "dev/stdin" : "run/input.txt";
const input = fs.readFileSync(filePath).toString().trim()

const inputYear = parseInt(input)

const isLeapYear = inputYear % 4 === 0 && inputYear % 100 !== 0 ? true : inputYear % 400 === 0
console.log(Number(isLeapYear))