/**
 * Created by YangCao on 2015/11/25.
 */
function PathMan(){
    this.serverPath = process.cwd() + "/";
    this.assetPath = this.serverPath + "/../serverAsset/";
}

PathMan.prototype.GetServerPath = function(){
    return this.serverPath;
}

module.exports = new PathMan();
