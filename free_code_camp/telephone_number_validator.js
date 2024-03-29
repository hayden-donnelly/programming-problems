function telephoneCheck(str) {
  if( 
  // 555-555-5555
  /^((1\s)*[0-9]{3})-[0-9]{3}-[0-9]{4}$/.test(str)
  // (555)555-5555
  || /^((1)*\([0-9]{3}\))[0-9]{3}-[0-9]{4}$/.test(str)
  // (555) 555-5555
  || /^((1\s)*\([0-9]{3}\))\s[0-9]{3}-[0-9]{4}$/.test(str)
   // 555 555 5555
  || /^(1)\s[0-9]{3}\s[0-9]{3}\s[0-9]{4}$/.test(str)
  // 1 555 555 5555
  || /^[0-9]{10}$/.test(str)) {
    return true;
  }
  return false;
}
