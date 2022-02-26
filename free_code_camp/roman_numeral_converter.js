const converter = {
  3: "M",
  2: "C",
  1: "X",
  0: "I",
  10: "V",
  11: "L",
  12: "D",
};

function addPlaces(placeCount, char) {
  let numeral = "";
  for(let i = 0; i < placeCount; i++) {
    numeral += char;
  }
  return numeral;
}

function convertToRoman(num) {
  let numeral = "";

  for(let i = 3; i >= 0; i--) {
    let placeCount = Math.floor(num/Math.pow(10, i));
    num -= Math.pow(10, i) * placeCount;

    if(placeCount == 0) {
      continue;
    }
    else if(placeCount >= 5) {
      if(placeCount == 9) {
        numeral += converter[i] + converter[i+1];
        continue;
      }
      placeCount -= 5;
      numeral += converter[i+10] + addPlaces(placeCount, converter[i]);
    }
    else if(placeCount <= 3) {
      numeral += addPlaces(placeCount, converter[i]);
    }
    else {
      numeral += converter[i] + converter[i+10];
    }
  }

 return numeral;
}
