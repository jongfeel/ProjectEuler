const isPrime = number => {
    if (number < 2) {
        return false;
    }

    const sqrt = Math.sqrt(number);
    for (let i = 2; i <= sqrt; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
};

const isEven = number => number % 2 == 0;

let seriesIndex = 0;
let seriesA = 0;
let seriesB = 0;

for (let a = -999; a < 1000; a++) {
    for (let b = -999; b < 1000; b++) {
        if ( (isEven(a) && !isEven(b)) || (!isEven(a) && isEven(b)) ) {
            continue;
        }
        let n = 0;
        while (isPrime(n ** 2 + a * n + b)) {
            n++;
        }
        if (seriesIndex < n) {
            //console.log(`a=${a}, b=${b}, n=${n}`);
            seriesA = a;
            seriesB = b;
            seriesIndex = n;
        }
        
    }
}

console.log(seriesA * seriesB);