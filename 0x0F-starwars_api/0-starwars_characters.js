#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

request(url, function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const res = JSON.parse(body).characters;
    for (const val of res) {
      request(val, function (error2, response2, body2) {
        if (error2) {
          console.log(error2);
        } else {
          const resChar = JSON.parse(body2).name;
          console.log(resChar);
        }
      });
    }
  }
});
