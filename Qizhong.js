var http = require("http");
var url = require("url");
var fs = require("fs");

function searchScore(res, id) {
	fs.readFile("./chengji.csv", 'utf-8', function(err, data) {
		vec = data.toString().split("\n");
		//res.write(data)
		for(var i = 0; i < vec.length; i++) {
			var tid = vec[i].split(",")[0]
			if(tid === id) {
				res.write(vec[i]);
				res.end();
			}
		}
	});
}

http.createServer(function(req, res){
    res.writeHeader(200, {'Content-Type':'text/javascript;charset=UTF-8'});  //状态码+响应头属性
    // 解析 url 参数
    var params = url.parse(req.url, true).query;  //parse将字符串转成对象,req.url="/?url=123&name=321"，true表示params是{url:"123",name:"321"}，false表示params是url=123&name=321
    res.write("上机课我讲习题的时候大家都提提问题，我都快单机了");
    res.write("\n");
    res.write("学号,姓名,第一大题,第二大题,第三大题,第四大题,第五大题,总分");
    res.write("\n");
    searchScore(res, params.id);
}).listen(2018);