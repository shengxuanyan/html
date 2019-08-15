(function(w,d){
    d.querySelector('body').addEventListener('click',function(e){
        addlike(e);

    })
    d.querySelector('.like-wrap').addEventListener('click',function(){
        this.classList.toggle('like-active');
        addLike(e);
    })
    d.querySelector('.content').addEventListener('click', function(e) {
        addLike(e);
      });
    var newarr=[];
    function addlike(e){
        //console.log(e);
        var newdiv=d.createElement('div');
        newdiv.classList.add('like');
        newdiv.innerHTML='<i class="fa fa-heart"></i>';
        //创建一个新队列
       
        d.body.appendChild(newdiv);
        newarr.push({
            el:newdiv,            //div源
            top: e.clientY,    //e为传入的点击事件，client取得点击位置像素
            left: e.clientX,
            opacity: 1,             //透明度
            scale: 1,               //放大倍数
            color: `rgb(${255*Math.random()},${255*Math.random()},${255*Math.random()})`
            //随机颜色，``反单引号为ES6写法，${}插入变量，也可用使用字符串拼接
        });
        movelike();
    }
    //处理
    function movelike(){
        //遍历新队列
        for(var i=0;i<newarr.length;i++){
            
            //判断是否消除 opacity=0
            if(newarr[i].opacity <=0) {          //透明小于0时
                d.body.removeChild(newarr[i].el);  //body去除like
                newarr.splice(i, 1);               //队列删减
                return;                             //跳出moveLike函数
            }


            //透明度逐渐减小
            newarr[i].opacity-=0.01;
            //逐渐上移top减一
            newarr[i].top-=1;
            //放大倍数操作
            newarr[i].scale+=0.01;

            //数值都改变以后 给元素添加样式es6
            newarr[i].el.style.cssText = `
            top: ${newarr[i].top}px;
            left: ${newarr[i].left}px;
            color: ${newarr[i].color};
            opacity: ${newarr[i].opacity};
            transform: scale(${newarr[i].scale});`
            //console.log(newarr[i].el.style.top);
        }
        
        w.requestAnimationFrame(movelike);
    }
})(window,document)