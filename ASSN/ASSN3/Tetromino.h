#ifndef CSED232_TETROMINO_H
#define CSED232_TETROMINO_H

#include "Block.h"
#include "const.h"
#include "Board.h"
#include "unistd.h"
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

class Block;
class BlockList;

/**
 * @brief 테트리미노를 관리하는 기본 클래스
 */
class Tetromino {
private:
    Position SRSDataSet[8][5]{}; /// @brief SRS 오프셋 데이터셋
    Block* blocks[4]{}; /// @brief 테트리미노의 블럭들 배열
    Board* board{}; /// @brief 테트리미노가 사용할 보드

    int color = RESET; /// @brief 테트리미노의 색상
    int rotate_num = 1; /// @brief 테트리미노의 회전 상태

    Position blockPosition[4]; /// @brief 블럭들의 상대 좌표 배열

    /// @brief 테트리미노의 충돌 여부를 확인하는 메서드
    bool isHit(int dx, int dy, bool checkCeiling);

    /// 블럭이 멈춰야 할 상태인지 체크하는 메서드
    bool checkStop();

    /// 블럭을 멈추는 메서드
    int stop();


protected:
    /// @brief SRS 오프셋 데이터셋을 저장하는 메서드
    void setSRSDataSet(Position set[][5]);

    /// @brief 테트로미노를 초기화하는 가상 메서드
    virtual void initTetromino(int x, int y);

    /// @brief SRS 오프셋 데이터셋을 생성하는 가상 메서드
    virtual void SRSTestSetGenerator();

    /// @brief 블록의 상대좌표를 설정하는 가상 메서드
    virtual void relativePositionGenerator(Position* _blockPosition);

    /// @brief 블록의 색상을 설정하는 가상 메서드
    virtual int colorGenerator();

public:
    /// @brief 인덱스로 블록 주소를 반환 하는 메서드
    Block& getBlockByIdx(int i);

    /// @brief 블럭들의 문자를 설정하는 메서드
    void setStr(string& target);

    /// @brief 블럭들을 그림자 블럭으로 설정하는 메서드
    void setShadowMino(bool isShadow);

    /// @brief 테트리미노의 복사 = 오버로딩
    Tetromino&operator=(const Tetromino& param);

    /// @brief 테트리미노의 디폴트 생성자
    Tetromino() = default;

    /// @brief 테트리미노의 생성자
    Tetromino(BlockList& blockList, Board* _board);

    /// @brief 임의 블록들로 테트리미노를 만드는 생성자
    Tetromino(BlockList& blockList, Board* _board, Block* customBlocks[4]);

    /// @brief 테트리미노를 회전하는 메서드
    virtual void rotate(int direction);

    /// @brief 테트리미노를 움직이는 메서드
    void move(int dx, int dy, bool checkCeiling);

    /// @brief 테트리미노의 멈춤 여부를 반환하는 메서드
    bool isStop();

    /// @brief 게임 틱마다 실행되는 메서드
    void onTick();

    /// @brief 테트리미노를 하드 드롭 하는 메서드
    void hardDrop();


};

/**
 * @brief I 미노를 관리하는 derived 클래스
 */
class Mino_I: public Tetromino{
private:
    /// @brief I 미노의 SRS 오프셋 데이터셋 지정
    void SRSTestSetGenerator() override;

    /// @brief I 미노 블럭들의 상대좌표를 지정하는 메서드
    void relativePositionGenerator(Position* _blockPosition) override;

    /// @brief I 미노의 색상을 지정하는 메서드
    int colorGenerator() override;

public:
    /// @brief I 테트리미노의 생성자
    Mino_I(int x, int y, BlockList& _blockList, Board* _board);;
};

/**
 * @brief O 미노를 관리하는 derived 클래스
 */
class Mino_O: public Tetromino{

private:
    /// @brief O 미노 블럭들의 상대좌표를 지정하는 메서드
    void relativePositionGenerator(Position* _blockPosition) override;

    /// @brief O 미노의 색상을 지정하는 메서드
    int colorGenerator() override;
    
public:
    /// @brief O 테트리미노의 생성자
    Mino_O(int x, int y, BlockList& _blockList, Board* _board);;;

    /// @brief O 테트리미노의 회전 메서드
    void rotate(int direction) override { }
};

/**
 * @brief T 미노를 관리하는 derived 클래스
 */
class Mino_T: public Tetromino{
private:
    /// @brief T 미노 블럭들의 상대좌표를 지정하는 메서드
    void relativePositionGenerator(Position* _blockPosition) override;

    /// @brief T 미노의 색상을 지정하는 메서드
    int colorGenerator() override;
    
public:
    /// @brief T 테트리미노의 생성자
    Mino_T(int x, int y, BlockList& _blockList, Board* _board);;

};

/**
 * @brief L 미노를 관리하는 derived 클래스
 */
class Mino_L: public Tetromino{
private:
    /// @brief L 미노 블럭들의 상대좌표를 지정하는 메서드
    void relativePositionGenerator(Position* _blockPosition) override;

    /// @brief L 미노의 색상을 지정하는 메서드
    int colorGenerator() override;
    
public:
    /// @brief L 테트리미노의 생성자
    Mino_L(int x, int y, BlockList& _blockList, Board* _board);;
};


/**
 * @brief J 미노를 관리하는 derived 클래스
 */
class Mino_J: public Tetromino{
private:
    /// @brief J 미노 블럭들의 상대좌표를 지정하는 메서드
    void relativePositionGenerator(Position* _blockPosition) override;

    /// @brief J 미노의 색상을 지정하는 메서드
    int colorGenerator() override;
public:
    /// @brief J 테트리미노의 생성자
    Mino_J(int x, int y, BlockList& _blockList, Board* _board);;
};


/**
 * @brief S 미노를 관리하는 derived 클래스
 */
class Mino_S: public Tetromino{
private:
    /// @brief S 미노 블럭들의 상대좌표를 지정하는 메서드
    void relativePositionGenerator(Position* _blockPosition) override;

    /// @brief S 미노의 색상을 지정하는 메서드
    int colorGenerator() override;
public:
    /// @brief S 테트리미노의 생성자
    Mino_S(int x, int y, BlockList& _blockList, Board* _board);;
};


/**
 * @brief Z 미노를 관리하는 derived 클래스
 */
class Mino_Z: public Tetromino{
private:
    /// @brief Z 미노 블럭들의 상대좌표를 지정하는 메서드
    void relativePositionGenerator(Position* _blockPosition) override;

    /// @brief Z 미노의 색상을 지정하는 메서드
    int colorGenerator() override;
public:
    /// @brief Z 테트리미노의 생성자
    Mino_Z(int x, int y, BlockList& _blockList, Board* _board);;


};
#endif //CSED232_TETROMINO_H
