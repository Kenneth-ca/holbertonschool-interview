#!/usr/bin/node

const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`;
request(url, async function (error, response, body) {
  if (error) {
    return console.log(error);
  } else {
    const values = JSON.parse(body).values;
    for (const val in values) {
      const res = await new Promise((resolve, reject) => {
        request(values[val], (error2, res, html) => {
          if (error2) {
            reject(error2);
          } else {
            resolve(JSON.parse(html).name);
          }
        });
      });
      console.log(res);
    }
  }
});
