#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

request(url, async function (error, response, body) {
  if (error) {
    return console.log(error);
  } else {
    const res = JSON.parse(body).characters;
    for (const val of res) {
      const res = await new Promise((resolve, reject) => {
        request(val, function (error2, response2, body2) {
          if (error2) {
            reject(error2);
          } else {
            resolve(JSON.parse(body2).name);
          }
        });
      });
      console.log(resChar);
    }
  }
});
