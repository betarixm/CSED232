#include "Tetromino.h"
#include "BlockList.h"

/*
 *
 *  ██╗  ██╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗
 *  ██║  ██║██╔═══██╗████╗  ██║██╔═══██╗██╔══██╗
 *  ███████║██║   ██║██╔██╗ ██║██║   ██║██████╔╝
 *  ██╔══██║██║   ██║██║╚██╗██║██║   ██║██╔══██╗
 *  ██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║
 *  ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝
 *
 *        ██████╗ ██████╗ ██████╗ ███████╗
 *       ██╔════╝██╔═══██╗██╔══██╗██╔════╝
 *       ██║     ██║   ██║██║  ██║█████╗
 *       ██║     ██║   ██║██║  ██║██╔══╝
 *       ╚██████╗╚██████╔╝██████╔╝███████╗
 *        ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
 *
 *
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 *
 */

/**
 * @brief 테트리미노의 충돌 여부를 확인하는 메서드
 * @param dx x 방향 이동 거리
 * @param dy y 방향 이동 거리
 * @param checkCeiling 천장 체크 여부
 * @return 충돌 여부
 */
bool Tetromino::isHit(int dx, int dy, bool checkCeiling) {
    for(auto& i: blocks){ // 모든 블럭에 대해 탐색하면서
        int x = i->x() + dx;
        int y = i->y() + dy;

        // 범위에서 벗어나거나, 다른 블럭과 충돌할 경우
        if((!((0 <= x && x < COL) && (0 <= y))) || (board->XY(x, y) != nullptr && board->XY(x, y)->isStop())){
            return !(checkCeiling && y >= ROW); // 천장 체크 여부를 반영
        }
    }
    return false; // 아무것도 해당되지 않으면 false 반환
}

/**
 * @brief 블럭이 멈춰야 할 상태인지 체크하는 메서드
 * @return 블럭의 멈춤 여부
 */
bool Tetromino::checkStop() {
    board->setGameBoard(); // 게임 보드 세팅
    for(auto& i: blocks){ // 테트리미노의 블럭 탐색
        // 끝에 다다랐다면 멈춰야함을 반환
        if(i->y() == 0){
            return true;
        }
        // 블럭의 바로 아래 블럭 조회
        Block* test = board->XY(i->x(), i->y() - 1);
        // 바로 아래에 멈춘 블럭이 존재한다면 멈춰야 함을 반환
        if(test != nullptr && test->isStop()){
            return true;
        }
    }
    return false; // 아무것도 해당되지 않는 경우
}

/**
 * @brief 블럭을 멈추는 메서드
 * @return
 */
int Tetromino::stop() {
    for(auto& i: blocks){
        // 모든 블럭의 멈춤 메서드 호출 및 변경
        i->isStop() = true;
    }
    return 0;
}

/**
 * @brief SRS 오프셋 데이터셋을 저장하는 메서드
 * @param set 원본 오프셋 데이터
 */
void Tetromino::setSRSDataSet(Position (*set)[5]) {
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 5; j++){
            SRSDataSet[i][j] = set[i][j]; // 데이터 복사
        }
    }
}

/**
 * @brief 테트로미노를 초기화하는 가상 메서드
 * @param x 테트리미노의 x 축좌표
 * @param y 테트리미노의 y 축좌표
 */
void Tetromino::initTetromino(int x, int y) {
    SRSTestSetGenerator(); // SRS 테스트 오프셋 데이터셋 생성
    color = colorGenerator(); // 색상 생성
    relativePositionGenerator(blockPosition); // 블록 상대좌표 세트 설정
    for(int i = 0; i < 4; i++){ // 모든 블럭에 대해서
        blocks[i]->setAxis(x, y); // 축 설정
        blocks[i]->setRelative(blockPosition[i]); // 상대좌표 설정
        blocks[i]->setColor(this->color); // 색상 지정
    }
}

/**
 * @brief SRS 오프셋 데이터셋을 생성하는 가상 메서드
 */
void Tetromino::SRSTestSetGenerator() {

    // 일반적인 미노에 대한 오프셋들
    Position virtualSet[8][5] = {
            {Position( 0, 0), Position(-1, 0), Position(-1,-1), Position( 0,+2), Position(-1,+2)}, // L -> 2
            {Position( 0, 0), Position(-1, 0), Position(-1,-1), Position( 0,+2), Position(-1,+2)}, // L -> 0
            {Position( 0, 0), Position(+1, 0), Position(+1,+1), Position( 0,-2), Position(+1,-2)}, // 0 -> L
            {Position( 0, 0), Position(-1, 0), Position(-1,+1), Position( 0,-2), Position(-1,-2)}, // 0 -> R
            {Position( 0, 0), Position(+1, 0), Position(+1,-1), Position( 0,+2), Position(+1,+2)}, // R -> 0
            {Position( 0, 0), Position(+1, 0), Position(+1,-1), Position( 0,+2), Position(+1,+2)}, // R -> 2
            {Position( 0, 0), Position(-1, 0), Position(-1,+1), Position( 0,-2), Position(-1,-2)}, // 2 -> R
            {Position( 0, 0), Position(+1, 0), Position(+1,+1), Position( 0,-2), Position(+1,-2)}  // 2 -> L
    };

    // 위의 세트로 오브젝트의 데이터 지정
    setSRSDataSet(virtualSet);
}

/**
 * @brief 블록의 상대좌표를 설정하는 가상 메서드
 * @param _blockPosition 블럭 상대 좌표 목록
 */
void Tetromino::relativePositionGenerator(Position *_blockPosition) {
    // 각 블록의 상대 좌표를 설정
    _blockPosition[0].setPosition(1, 1);
    _blockPosition[1].setPosition(-1, 0);
    _blockPosition[2].setPosition(0, 0);
    _blockPosition[3].setPosition(1, 0);
}

/**
 * @brief 블록의 색상을 설정하는 가상 메서드
 * @return 블록의 색상
 */
int Tetromino::colorGenerator() {
    // 블록의 색상을 반환
    return WHITE;
}

/**
 * @brief 인덱스로 블록 주소를 반환 하는 메서드
 * @param i 인덱스
 * @return 인덱스의 블록 주소
 */
Block &Tetromino::getBlockByIdx(int i) {
    return *blocks[i];
}

/**
 * @brief 블럭들의 문자를 설정하는 메서드
 * @param target 설정할 문자
 */
void Tetromino::setStr(string &target) {
    for(auto&i : blocks){ // 모든 블럭들의 문자열 설정 메서드 호출
        i->setStr(target);
    }
}

/**
 * @brief 블럭들을 그림자 블럭으로 설정하는 메서드
 * @param isShadow 그림자 여부
 */
void Tetromino::setShadowMino(bool isShadow) {
    for(auto&i : blocks){ // 모든 블럭들의 그림자 여부 설정
        i->isShadow() = isShadow;
    }
}

/**
 * @brief 테트리미노의 복사 = 오버로딩
 * @param param 상대 테트리미노
 * @return
 */
Tetromino &Tetromino::operator=(const Tetromino &param) {
    if(&param != this){
        for(int i = 0; i < 4; i++){
            *blocks[i] = *(param.blocks[i]); // 블럭 정보 복사
        }
        board = param.board; // 보드 주소 복사
    }
    return *this;
}

/**
 * @brief 테트리미노의 기본 생성자
 * @param blockList 테트리미노가 사용할 기본 블록 리스트 오브젝트
 * @param _board 테트리미노의 기본 보드 주소
 */
Tetromino::Tetromino(BlockList &blockList, Board *_board) {
    for(auto& i: blocks){
        i = blockList.add(); // 블록 리스트에서 블록을 받아옴
    }
    this->board = _board; // 보드 지정
}

/**
 * @brief 임의 블록들로 테트리미노를 만드는 생성자
 * @param blockList 테트리미노가 사용할 기본 블록 리스트 오브젝트
 * @param _board 테트리미노의 기본 보드 주소
 * @param customBlocks 테트리미노에 추가될 임의의 블럭 주소 배열
 */
Tetromino::Tetromino(BlockList &blockList, Board *_board, Block **customBlocks) {
    for(int i = 0; i < 4; i++){ // 블록을 임의의 블록 주소로 설정
        blocks[i] = customBlocks[i];
        blockList.append(customBlocks[i]); // 설정된 블록을 블록 리스트에 등록
    }
    this->board = _board; // 보드 설정
}

/**
 * @brief 테트리미노를 회전하는 메서드
 * @param direction 회전 방향
 */
void Tetromino::rotate(int direction) {
    // SRS 데이터셋의 ROW 커서
    int cursor = rotate_num * 2 + (direction + 1) / 2;

    for(auto& i: blocks){ // 모든 블록에 대해 우선 회전 수행
        i->rotate(direction);
    }

    // SRS 데이터셋 조회
    for(auto& i: SRSDataSet[cursor]){
        for(auto& b: blocks){ (*b) += i; } // SRS 데이터 적용

        if(isHit(0, 0, true)){
            // 불가능한 위치라면 SRS 데이터 적용 되돌림
            for(auto& b: blocks){ (*b) -= i; }
        } else {
            // 가능한 위치라면 rotate_num을 설정하고 종료함.
            // rotate_num: 0: L, 1: 0, 2: R, 3: 2
            rotate_num += direction;
            rotate_num = (rotate_num < 0) ? (3) : ((3 < rotate_num) ? (0) : (rotate_num));
            return;
        }
    }

    // SRS의 모든 경우에 실패한 경우
    for(auto& i: blocks){
        // 블럭 회전을 되돌린다.
        i->rotate(-1 * direction);
    }

}

/**
 * @brief 테트리미노를 움직이는 메서드
 * @param dx 움직일 x 거리
 * @param dy 움직일 y 거리
 * @param checkCeiling 천장 체크 여부
 */
void Tetromino::move(int dx, int dy, bool checkCeiling) {
    if(isHit(dx, dy, checkCeiling)) return; // 가능한 위치가 아니라면 종료
    for(auto& i: blocks){ // 모든 블럭에 대해
        if(!i->isStop()){ // 멈춘 블럭이 아니라면 축 이동 시행
            *i += Position(dx, dy);
        }
    }
}

/**
 * @brief 테트리미노의 멈춤 여부를 반환하는 메서드
 * @return 테트리미노의 멈춤 여부
 */
bool Tetromino::isStop() {
    for(auto& i:blocks){
        // 블럭 중에 멈춘 블럭이 있다면 true 반환
        if(i->isStop()){
            return true;
        }
    }

    // 아니라면 false 반환
    return false;
}

/**
 * @brief 게임 틱마다 실행되는 메서드
 */
void Tetromino::onTick() {
    checkStop() && stop(); // 멈춰야할 상황이라면 멈춘다
    move(0, -1, false); // 아래로 한칸 이동
}

/**
 * @brief 테트리미노를 하드 드롭 하는 메서드
 */
void Tetromino::hardDrop() {
    for(int dy = 0; dy >= (-1 * ROW); dy--){
        // 자신 보다 아래의 y 좌표에서 부딪히는 곳이 있다면 그곳으로 이동한다.
        if(isHit(0, dy - 1, true)){
            move(0, dy, true);
            break;
        }
    }
}

/**
 * @brief I 미노의 SRS 오프셋 데이터셋 지정
 */
void Mino_I::SRSTestSetGenerator() {
    Position virtualSet[8][5] = {
            { Position( 1,  0), Position(-1,  0), Position( 2,  0), Position(-1, -1), Position( 2,  2) },
            { Position( 0,  1), Position( 1,  1), Position(-2,  1), Position( 1, -1), Position(-2,  2) },
            { Position( 0, -1), Position(-1, -1), Position( 2, -1), Position(-1,  1), Position( 2, -2) },
            { Position( 1,  0), Position(-1,  0), Position( 2,  0), Position(-1, -1), Position( 2,  2) },
            { Position(-1,  0), Position( 1,  0), Position(-2,  0), Position( 1,  1), Position(-2, -2) },
            { Position( 0, -1), Position(-1, -1), Position( 2, -1), Position(-1,  1), Position( 2, -2) },
            { Position( 0,  1), Position( 1,  1), Position(-2,  1), Position( 1, -1), Position(-2,  2) },
            { Position(-1,  0), Position( 1,  0), Position(-2,  0), Position( 1,  1), Position(-2, -2) }
    };
    // 사용할 데이터로 지정
    setSRSDataSet(virtualSet);
}

/**
 * @brief I 미노 블럭들의 상대좌표를 지정하는 메서드
 * @param _blockPosition 테트리미노 블럭 상대좌표 배열
 */
void Mino_I::relativePositionGenerator(Position *_blockPosition) {
    _blockPosition[0].setPosition(-1, 0);
    _blockPosition[1].setPosition(0, 0);
    _blockPosition[2].setPosition(1, 0);
    _blockPosition[3].setPosition(2, 0);
}

/**
 * @brief I 미노의 색상을 지정하는 메서드
 * @return 테트리미노의 색상
 */
int Mino_I::colorGenerator() {
    return CYAN;
}

/**
 * @brief I 테트리미노의 생성자
 * @param x 축 x 좌표
 * @param y 축 y 좌표
 * @param _blockList 사용할 블록리스트 오브젝트
 * @param _board 사용할 보드 오브젝트
 */
Mino_I::Mino_I(int x, int y, BlockList &_blockList, Board *_board) : Tetromino(_blockList, _board){
    Mino_I::initTetromino(x, y);
}

/**
 * @brief O 미노 블럭들의 상대좌표를 지정하는 메서드
 * @param _blockPosition 테트리미노 블럭 상대좌표 배열
 */

void Mino_O::relativePositionGenerator(Position *_blockPosition) {
    _blockPosition[0].setPosition(0,  0);
    _blockPosition[1].setPosition(1,  0);
    _blockPosition[2].setPosition(0, -1);
    _blockPosition[3].setPosition(1, -1);
}

/**
 * @brief O 미노의 색상을 지정하는 메서드
 * @return 테트리미노의 색상
 */
int Mino_O::colorGenerator() {
    return YELLOW;
}

/**
 * @brief O 테트리미노의 생성자
 * @param x 축 x 좌표
 * @param y 축 y 좌표
 * @param _blockList 사용할 블록리스트 오브젝트
 * @param _board 사용할 보드 오브젝트
 */
Mino_O::Mino_O(int x, int y, BlockList &_blockList, Board *_board) : Tetromino(_blockList, _board){
    Mino_O::initTetromino(x, y);
}

/**
 * @brief T 미노 블럭들의 상대좌표를 지정하는 메서드
 * @param _blockPosition 테트리미노 블럭 상대좌표 배열
 */
void Mino_T::relativePositionGenerator(Position *_blockPosition) {
    _blockPosition[0].setPosition( 0,  1);
    _blockPosition[1].setPosition(-1,  0);
    _blockPosition[2].setPosition( 0,  0);
    _blockPosition[3].setPosition( 1,  0);
}

/**
 * @brief T 미노의 색상을 지정하는 메서드
 * @return 테트리미노의 색상
 */
int Mino_T::colorGenerator() {
    return MAGENTA;
}

/**
 * @brief T 테트리미노의 생성자
 * @param x 축 x 좌표
 * @param y 축 y 좌표
 * @param _blockList 사용할 블록리스트 오브젝트
 * @param _board 사용할 보드 오브젝트
 */
Mino_T::Mino_T(int x, int y, BlockList &_blockList, Board *_board) : Tetromino(_blockList, _board){
    Mino_T::initTetromino(x, y);
}

/**
 * @brief L 미노 블럭들의 상대좌표를 지정하는 메서드
 * @param _blockPosition 테트리미노 블럭 상대좌표 배열
 */
void Mino_L::relativePositionGenerator(Position *_blockPosition) {
    _blockPosition[0].setPosition( 1,  1);
    _blockPosition[1].setPosition(-1,  0);
    _blockPosition[2].setPosition( 0,  0);
    _blockPosition[3].setPosition( 1,  0);
}

/**
 * @brief L 미노의 색상을 지정하는 메서드
 * @return 테트리미노의 색상
 */
int Mino_L::colorGenerator() {
    return WHITE;
}

/**
 * @brief L 테트리미노의 생성자
 * @param x 축 x 좌표
 * @param y 축 y 좌표
 * @param _blockList 사용할 블록리스트 오브젝트
 * @param _board 사용할 보드 오브젝트
 */
Mino_L::Mino_L(int x, int y, BlockList &_blockList, Board *_board) : Tetromino(_blockList, _board){
    Mino_L::initTetromino(x, y);
}

/**
 * @brief J 미노 블럭들의 상대좌표를 지정하는 메서드
 * @param _blockPosition 테트리미노 블럭 상대좌표 배열
 */
void Mino_J::relativePositionGenerator(Position *_blockPosition) {
    _blockPosition[0].setPosition(-1,  1);
    _blockPosition[1].setPosition(-1,  0);
    _blockPosition[2].setPosition( 0,  0);
    _blockPosition[3].setPosition( 1,  0);
}

/**
 * @brief J 미노의 색상을 지정하는 메서드
 * @return 테트리미노의 색상
 */
int Mino_J::colorGenerator() {
    return BLUE;
}

/**
 * @brief J 테트리미노의 생성자
 * @param x 축 x 좌표
 * @param y 축 y 좌표
 * @param _blockList 사용할 블록리스트 오브젝트
 * @param _board 사용할 보드 오브젝트
 */
Mino_J::Mino_J(int x, int y, BlockList &_blockList, Board *_board) : Tetromino(_blockList, _board){
    Mino_J::initTetromino(x, y);
}

/**
 * @brief S 미노 블럭들의 상대좌표를 지정하는 메서드
 * @param _blockPosition 테트리미노 블럭 상대좌표 배열
 */
void Mino_S::relativePositionGenerator(Position *_blockPosition) {
    _blockPosition[0].setPosition( 0,  1);
    _blockPosition[1].setPosition( 1,  1);
    _blockPosition[2].setPosition(-1,  0);
    _blockPosition[3].setPosition( 0,  0);
}

/**
 * @brief S 미노의 색상을 지정하는 메서드
 * @return 테트리미노의 색상
 */
int Mino_S::colorGenerator() {
    return GREEN;
}

/**
 * @brief S 테트리미노의 생성자
 * @param x 축 x 좌표
 * @param y 축 y 좌표
 * @param _blockList 사용할 블록리스트 오브젝트
 * @param _board 사용할 보드 오브젝트
 */
Mino_S::Mino_S(int x, int y, BlockList &_blockList, Board *_board) : Tetromino(_blockList, _board) {
    Mino_S::initTetromino(x, y);
}

/**
 * @brief Z 미노 블럭들의 상대좌표를 지정하는 메서드
 * @param _blockPosition 테트리미노 블럭 상대좌표 배열
 */
void Mino_Z::relativePositionGenerator(Position *_blockPosition) {
    _blockPosition[0].setPosition( -1,  1);
    _blockPosition[1].setPosition( 0,  1);
    _blockPosition[2].setPosition( 0,  0);
    _blockPosition[3].setPosition( 1,  0);
}

/**
 * @brief Z 미노의 색상을 지정하는 메서드
 * @return 테트리미노의 색상
 */
int Mino_Z::colorGenerator() {
    return RED;
}

/**
 * @brief Z 테트리미노의 생성자
 * @param x 축 x 좌표
 * @param y 축 y 좌표
 * @param _blockList 사용할 블록리스트 오브젝트
 * @param _board 사용할 보드 오브젝트
 */
Mino_Z::Mino_Z(int x, int y, BlockList &_blockList, Board *_board) : Tetromino(_blockList, _board){
    Mino_Z::initTetromino(x, y);
}
