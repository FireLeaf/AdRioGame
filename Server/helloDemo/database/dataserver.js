/**
 * New node file
 */
function sqlClient(response){
	var mysql = require('mysql');
	
	var TEST_DATABASE = 'games';
	
	
	//创建连接  
	var client = mysql.createConnection({
	    host: '127.0.0.1',
	    port: '3306',
	    user: 'root',
	    password: 'root',
	});
	
	client.connect();
	client.query("use " + TEST_DATABASE);
	
	this.query = function(querySql){
		client.query(querySql,
			function selectCb(err, results, fields) {
			    if (err) {
			        throw err;
			    }
	
			    if (results !=null && results.length != 0) {
			    	response.end("true");
			    }
			    client.end();
			}
		);
		
	}
}

module.exports = sqlClient;


