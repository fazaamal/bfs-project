const prompt = require("prompt-sync")();

function main(){
    let flag = [];
    let pred = [];
    let queue = [];
    let matrix = [
        [0,0,1,1,0,1,1,0],
        [0,0,0,1,1,0,0,1],
        [1,0,0,1,0,1,0,0],
        [1,1,1,0,1,0,0,0],
        [0,1,0,1,0,1,1,1],
        [1,0,1,0,1,0,0,1],
        [1,0,0,0,1,0,0,0],
        [0,1,0,0,1,1,0,1]
    ];

    console.log(matrix);

    let start = parseInt(prompt('Enter the starting vertex: '));
    queue.push(start);

    for(let rowIdx in matrix){
        flag[rowIdx] = false;
        pred[rowIdx] = null;
    }

    flag[start] = true;
    console.log(flag);
    console.log(pred);

    while(queue.length!==0){
        let vertex = queue.splice(0, 1)[0];
        let row = matrix[vertex];
        console.log(row);
        for(let idx in row){
            if(!flag[idx] && row[idx]==1){
                queue.push(parseInt(idx));
                flag[idx] = true;
                pred[idx] = vertex;
            }else{
                continue;
            }
        }

        console.log(queue);
    }

    console.log(flag);
    console.log(pred);
}

main();