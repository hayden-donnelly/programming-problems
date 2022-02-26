function telephoneCheck(str) {
  if(/[0-9]{3}-[0-9]{3}-[0-9]{4}/.test(str)) {
    return true;
  } else if (/\([0-9]{3}\)[0-9]{3}-[0-9]{4}/.test(str)) {
    return true;
  } else if (/\([0-9]{3}\)\s[0-9]{3}-[0-9]{4}/.test(str)) {
    return true;
  } else if(/[0-9]{3}\s[0-9]{3}\s[0-9]{4}/.test(str)) {
    return true;
  } else if(/[0-9]{10}/.test(str)) {
    return true;
  } else if(/1\s[0-9]{3}\s[0-9]{3}\s[0-9]{4}/.test(str)) {
    return true;
  }
  return false;
}
