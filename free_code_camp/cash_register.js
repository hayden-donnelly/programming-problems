const units = {
  "PENNY": 0.01,
  "NICKEL": 0.05,
  "DIME": 0.1,
  "QUARTER": 0.25,
  "ONE": 1.00,
  "FIVE": 5.00,
  "TEN": 10.00,
  "TWENTY": 20.00,
  "ONE HUNDRED": 100.00,
}

function checkCashRegister(price, cash, cid) {
  let amountDue = cash - price;
  
  for(let i = cid.length-1; i >= 0; i--) {
    let subtractionAmount = units[cid[i][0]];
    
    while(amountDue >= cid[i][1]) {
      amountDue -= subtractionAmount;
      cid[i][1] -= subtractionAmount;
    }
  }

  return {status: _status, change: _change};
}
