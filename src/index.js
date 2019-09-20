
let isFloat = (x)=>String(x).indexOf('.')<0?false:true
function getFinalData(initData){
  return initData.map(item=>{
    let tArr =  item.reduce((totle,current,index,arr)=>{
    let {before,after,s} = current
    if(index===arr.length-1)
      return typeof totle[totle.length-1] === 'number'?totle.concat([s,after]):totle.concat([before,s,after])
    else
      return s==='/'?totle.concat([before,s,after]):typeof totle[totle.length-1] === 'number'?totle.concat([s]):totle.concat([before,s])
  },[])
  return tArr.join('')+'='+eval(tArr.join(''))
  }).filter((item)=>!isFloat(item.split('=')[1]))
}
module.exports = getFinalData;