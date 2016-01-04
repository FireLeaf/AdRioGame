/**
 * Created by pc on 2015/9/14.
 */

var Client = require('./Client.js');

var MAX_ONLINE_CLIENT = 3000;

function GenerateSession(){

}

function ClientManager(){
    this.UserTable = new Array(MAX_ONLINE_CLIENT);
    this.UselessSlot = new Array(MAX_ONLINE_CLIENT);
}

ClientManager.prototype.addClient = function(userID){

}

module.exports = new ClientManager();