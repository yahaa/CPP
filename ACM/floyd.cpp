void floyd(){　　　　　　//　　
	for(int k=1;k<=n;k++)   //第一层循环表示分别以　　１......n　为中转站更新各个点之间的距离

		for(int i=1;i<=n;i++)  //这两层循环更新的是　　每次以　　k为中转站是　　各个点之间的最短距离
			for(int j=1;j<=n;j++){
				maps[i][j]=min(maps[i][j],maps[i][k]+maps[k][j]);  //等价于  //if(maps[i][j]>maps[i][k]+maps[k][j])
			}                                                           //maps[i][j]=maps[i][k]+maps[k][j];
}


/*从任意节点i到任意节点j的最短路径不外乎2种可能，1是直接从i到j，2是从i经过若干个节点k到j。
所以，我们假设Dis(i,j)为节点u到节点v的最短路径的距离，
对于每一个节点k，我们检查Dis(i,k) + Dis(k,j) < Dis(i,j)是否成立，
如果成立，证明从i到k再到j的路径比i直接到j的路径短，我们便设置Dis(i,j) = Dis(i,k) + Dis(k,j)，
这样一来，当我们遍历完所有节点k，Dis(i,j)中记录的便是i到j的最短路径的距离。　*/

