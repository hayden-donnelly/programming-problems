function palindrome(str) {
    str = str.split(" ").join("")
    const arr = str.split("");
    console.log(arr)
    console.log(str)
    let str2 = "";
    for(let i = str.length-1; i >= 0; i--) {
      str2 += arr[i];
    }
    console.log(str2);
    if(str == str2) {
      return true;
    }
    return false;
  }