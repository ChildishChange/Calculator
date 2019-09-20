const getFinalData = require('./src/index');
let testData = [
  [
    {
      before:12,
      s:'*',
      after:14
    },
    {
      before:14,
      s:'+',
      after:17
    }
    
  ]
]
test('adds 1 + 2 to equal 3', () => {
  expect(getFinalData(testData)).toEqual(['12*14+17=185']);
});