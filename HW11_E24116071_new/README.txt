1.主線劇情:玩家被邀請至霍格華茲就讀，而本學期的任務是打敗伏地魔
2.地圖:
	(1)移動方式:按W、S、A、D表示上下左右
	(2)地圖數量:共有三張地圖，越後面的地圖battle的難度越高，伏地魔會出現在最後一張地圖
	(3)地圖事件(完成事件後會從地圖上消失):
		a.C:表示課堂，會有簡單的互動問答，然後會提供有關寶物在哪裡的資訊
		b.B:表示戰鬥，後續會有詳細說明
		c.N:代表npc，推進主線劇情
		d.T:代表三根掃帚(一家餐酒館)，玩家可以在那裏跟神秘男人做交易，用金錢換取升等
		e.S:玩家初始位置
		f.D:換地圖點，如果選擇換圖則無法回頭，在最後一張地圖不會有D
3.戰鬥(完成戰鬥後會從地圖上消失):
	(1)遇到battle事件時，選Y呼叫幫手，選E逃脫，選其他按鍵獨自進入戰鬥
		->選Y:有三個角色，可在選單中看見幫手巫師的技能，輸入編號後兩位巫師(玩家和幫手)將進入戰鬥
	(2)戰鬥順序是玩家先攻，有藥水的情況下會詢問要攻擊還是使用藥水(只能擇一)
		->選攻擊:會攻擊全部怪獸，造成的傷害=玩家的attack-怪物的defense*0.5
		->選藥水:會出現藥水清單，可按標號來使用對應的藥水，使用後藥水從背包中消失
	(3)玩家攻擊後，換幫手巫師攻擊，玩家可選擇要幫手巫師正常攻擊還是使用技能(只能擇一)
	(4)所有巫師攻擊完畢，換怪物攻擊，一次是攻擊全部的巫師，造成的傷害=怪物的attack-巫師的defense*0.5
	(5)當怪獸hp歸零，玩家勝利，會獲得經驗值和金錢作為獎勵，如果該戰鬥是稀有戰鬥(進入前會顯示)則獲勝會掉寶物，寶物自動進入玩家背包
	(6)如果玩家的hp比怪獸的更早歸零，表示玩家死亡，遊戲失敗，將退出遊戲
	(7)一張地圖中有兩個稀有戰鬥會掉寶物
4.背包:
	(1)按e可退出背包視窗，按想穿戴的物品編號在level required符合的情況下會穿戴到玩家身上(藥水不能穿戴，只能戰鬥中用)
	(2)玩家身上可以裝備一個weapon和一個armor
	(3)在身上已經有裝備的情況下如果想換成背包內的裝備，會先將身上的裝備收回背包，再穿上新的
	(4)完成裝備後，遊戲主畫面會顯示目前玩家身上的裝備名稱
5.勝利機制:打敗伏地魔，但如果在任何一場戰鬥中hp小於等於0，則遊戲失敗。
	
