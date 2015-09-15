/**
 * Created by pc on 2015/9/14.
 */

 function loginResponse(req, res, packet){

}

exports.RegisterHandler = function(registerHandler){
    registerHandler(TS_NetCode.NC_TS_LOGINREQUEST, loginResponse);
};