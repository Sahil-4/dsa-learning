// bubble sort algorithm
const bubbleSort = (arr) => {
  // takes an array and sort that using bubble sort
  for (let i = 1; i < arr.length; i++) {
    let isSorted = true;

    for (let j = 0; j < arr.length - i; j++) {
      if (arr[j].p > arr[j + 1].p) {
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        isSorted = false;
      }
    }

    if (isSorted) {
      break;
    }
  }
};

// Lecture 17 : Bubble Sort - p3() : stable algo or unstable algo

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

// before sorting
console.table(arr);

// sorting
bubbleSort(arr);

// after sorting
console.table(arr);

// hence we can say that bubble sort is an stable sorting algorithm
// because it does not changed the order of occurrence of similar elements
