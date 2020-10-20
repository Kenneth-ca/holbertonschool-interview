#!/usr/bin/node
const request = require('request');
const input = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + input;

request(url, async function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;
    for (const i in characters) {
      const res = await new Promise((resolve, reject) => {
        request(characters[i], (error, res, html) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(html).name);
          }
        });
      });
      console.log(res);
    }
  }
});
