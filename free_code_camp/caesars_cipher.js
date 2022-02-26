const alphabet = [  'A','B','C','D','E','F','G',
                    'H','I','J','K','L','M','N',
                    'O','P','Q','R','S','T','U',
                    'V','W','X','Y','Z' ];

function rot13(str) {
  let arr = str.split("");
  for(let i = 0; i < str.length; i++) {
    
    let index = alphabet.indexOf(arr[i]);
    if(index == -1) {
      continue;
    }

    index += 13;
    index = (index >= 26) ? index - 26 : index;
    arr[i] = alphabet[index];
  }

  str = arr.join("");
  return str;
}
