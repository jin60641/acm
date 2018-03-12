#include <stdio.h>
const int N = 310;
	
int main(){
	int nMagicSqr[N][N];
	int nN;
	
	void makeMagicSquare(int nMagicSqr[][N], int nN);
	void showMagicSquare(int nMagicSqr[][N], int nN);
	scanf("%d", &nN);
	makeMagicSquare(nMagicSqr, nN);
	showMagicSquare(nMagicSqr, nN);
	return 0;
}
	
void makeMagicSquare(int nMagicSqr[][N], int nN){
	void OddMagicSquare(int nMagicSqr[][N], int nN, int nOrgRow, int nOrgcol, int nBgn);
	void DblyEvenMagicSquare(int nMagicSqr[][N], int nN);
	void SnglyEvenMagicSquare(int nMagicSqr[][N], int nN);
	if( nN%2 ){
		OddMagicSquare(nMagicSqr, nN, 0, 0, 1 );
	} else if( nN % 4 == 0 ){
		DblyEvenMagicSquare(nMagicSqr, nN );
	} else {
		SnglyEvenMagicSquare(nMagicSqr, nN );
	}
}
	
void OddMagicSquare(int nMagicSqr[][N], int nN, int nOrgRow, int nOrgCol, int nBgn){
	int nRow = nOrgRow, nCol = nOrgCol + nN/2, nNmbr = nBgn, nCell = nN * nN + nBgn-1;
	nMagicSqr[nRow][nCol] = nBgn;
	while (++nNmbr <= nCell) {
		int nPrvRow = nRow, nPrvCol = nCol;
		nRow = (nRow - 1)<nOrgRow?nOrgRow+nN-1:nRow-1;
		nCol = (nCol + 1)>=(nN+nOrgCol)?nOrgCol:nCol+1;
		if (nMagicSqr[nRow][nCol]) {
			nRow = (nPrvRow + 1)>=(nN+nOrgRow)?nPrvRow:nPrvRow+1;
			nCol = nPrvCol;
		}
		nMagicSqr[nRow][nCol] = nNmbr;
	}
}
	
void DblyEvenMagicSquare(int nMagicSqr[][N], int nN){
	for(int i = 0; i < nN; i++)
		for(int j = 0; j < nN; j++)
			nMagicSqr[i][j] = ( ( (i>=j && (i-j) % 4 == 0 ) || ( j>=i && (j-i) % 4 == 0 ) ) || ((i+j+1) % 4 == 0) )?i*nN+j+1:nN*nN-(i*nN+j);
}
	
void SnglyEvenMagicSquare(int nMagicSqr[][N], int nN){
	int nH = nN / 2, nSqr = nH * nH;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			OddMagicSquare(nMagicSqr, nH, j * nH, (i ^ j) * nH, ((i * 2) + j) * nSqr + 1);
	int nQ = nH / 2;
	void SwitchHalf(int nMagicSqr[][N], int nCol, int nHalf);
	for (int nCol = 0; nCol < nQ; nCol++)
		SwitchHalf(nMagicSqr, nCol, nH);
	for (int nCol = nH + nQ + 2; nCol < nN; nCol++)
		SwitchHalf(nMagicSqr, nCol, nH);
	void Swap(int& x, int& y);;
	Swap(nMagicSqr[nQ][0], nMagicSqr[nQ + nH][0]);
	Swap(nMagicSqr[nQ][nQ], nMagicSqr[nQ + nH][nQ]);
}
	
void SwitchHalf(int nMagicSqr[][N], int nCol, int nHalf){
	void Swap(int& x, int& y);
	for (int nRow = 0; nRow < nHalf; nRow++)
		Swap(nMagicSqr[nRow][nCol], nMagicSqr[nRow + nHalf][nCol]);
}
	
void Swap(int& x, int& y){
	int t = x;
	x = y;
	y = t;
}
	
void showMagicSquare(int nMagicSqr[][N], int nN){
	for (int nRow = 0; nRow < nN; nRow++) {
		for (int nCol = 0; nCol < nN; nCol++)
			printf("%d ", nMagicSqr[nRow][nCol]);
		printf("\n");
	}
}
