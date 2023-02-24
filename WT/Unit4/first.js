var http = require('http');
var url = require('url');
var fs = require('fs');
var qs = require('querystring');
var MongoClient = require('mongodb').MongoClient;
var dburl = "mongodb://localhost:27017/";
http.createServer(function (request, response) 
{
    if (request.method == "GET") 
    {
        var myurl = url.parse(request.url)
        var pathname = myurl.pathname;
        MongoClient.connect(dburl, function (err, db) 
        {
            var dbo = db.db('employee_db');
            var query = myurl.query;
            var q2obj = qs.parse(query);
            dbo.collection('Employee').find(q2obj).toArray(function (err, result) 
            {
                if (err) throw err;
                response.writeHead(200,{ 'Content-Type': 'text/html' });
                response.write("<h1> Second part </h1>");
                for (var i = 0; i < result.length; i++) 
                {
                    response.write('<h1> Employee name : ' + 
                    JSON.stringify(result[i].emp_name) + ' Employee_ID : ' + JSON.stringify(result[i].emp_id) + '</h1>');
                }
                response.end();
                db.close();
            })
        })
    }
}).listen(8081);
console.log("Server started");