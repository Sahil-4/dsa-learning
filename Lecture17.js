const selectionSort = (arr) => {
  for (let i = 1; i < arr.length; i++) {
    for (let j = 0; j < arr.length - i; j++) {
      if (arr[j].p > arr[j + 1].p) {
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
};

const bubbleSort = (arr) => {
  for (let i = 0; i < arr.length; i++) {
    if (i == arr.length - 1) {
      break;
    }

    let min = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[j].p < arr[min].p) {
        min = j;
      }
    }

    let temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
};

const arr = [
  { f: "i", p: 9 },
  { f: "d", p: 3 },
  { f: "g", p: 7 },
  { f: "f", p: 6 },
  { f: "a", p: 1 },
  { f: "e", p: 5 },
  { f: "h", p: 8 },
  { f: "b", p: 1 },
  { f: "c", p: 3 },
];

// Lecture 17 : stable algo or unstable algo 

console.table(arr);

// selectionSort(arr);
// bubbleSort(arr);

console.table(arr);

