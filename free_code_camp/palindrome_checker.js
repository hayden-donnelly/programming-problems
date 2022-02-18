function palindrome(str) {
  str = str.replace(/\s/g, "");
  str = str.replace(/[^a-z0-9]/gi, "");
  str = str.toLowerCase();

  const arr = str.split("");
  let str2 = "";
  
  for(let i = str.length-1; i >= 0; i--) {
    str2 += arr[i];
  }
  
  if(str == str2) {
    return true;
  }
  return false;
}