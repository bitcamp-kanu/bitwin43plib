using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace _2017._01._11._001
{
    
    //이동 하는 방향을 나타 낸다.
    class Character : ICloneable
    {
        private int _nActionGap = 1;
        private Image _charImage = null;
        //한걸을에 움직이는 픽셀 
        private const int _SetpOne = 32;
        private const int _rutinSize = 4;
   
        //캐릭터의 위치를 나타 낸다.
        private Rectangle _rectLoc = new Rectangle();
        public enum eDirection { eDown = 0, eLeft = 1, eRight = 2, eUp = 3,eNone};
        private int _nStep = 0; //현재 스탬
        private eDirection _directtion = eDirection.eDown;

        private Size _itemSize;
        public Image CharImage
        {
            set
            {
                _charImage = value;
                _itemSize.Width = _charImage.Width / _rutinSize;
                _itemSize.Height = _charImage.Height / _rutinSize;

                _rectLoc.Width = _itemSize.Width;
                _rectLoc.Height = _itemSize.Height;
            }
        }
        public eDirection Direction
        {
            get { return _directtion; }
            set
            {
                _directtion = value;
                _nStep = 0;
            }
        }
        public Rectangle Loc
        {
            get { return _rectLoc;}
        }
        public Character()
        {
            _rectLoc.X = 0;
            _rectLoc.Y = 0;
        }
        public Character(Point loc, Image img)
        {
            _rectLoc.Location = loc;
            _charImage = img;


            _itemSize.Width = _charImage.Width / _rutinSize;
            _itemSize.Height = _charImage.Height / _rutinSize;

            _rectLoc.Width = _itemSize.Width;
            _rectLoc.Height = _itemSize.Height;

        }
        public void MoveUp()
        {
            if (_directtion == eDirection.eUp)
            {
                _rectLoc.Y -= _SetpOne;
                _nStep++;
                _nStep %= (_rutinSize * 2);
            }
            else
            {
                _directtion = eDirection.eUp;
                _nStep = 0;
            }
        }
        public void MoveDown()
        {
            if (_directtion == eDirection.eDown)
            {

                _rectLoc.Y +=_SetpOne;
                _nStep++;
                _nStep %= (_rutinSize * 2);
            }
            else
            {
                _directtion = eDirection.eDown;
                _nStep = 0;
            }
        }
        public void MoveLeft()
        {
            if (_directtion == eDirection.eLeft)
            {
                _rectLoc.X-=_SetpOne;
                _nStep++;
                _nStep %= (_rutinSize * 2);
            }
            else
            {
                _directtion = eDirection.eLeft;
                _nStep = 0;
            }
        }
        public void MoveRight()
        {
            if (_directtion == eDirection.eRight)
            {
                _rectLoc.X += _SetpOne;
                _nStep++;
                _nStep %= (_rutinSize * 2);
            }
            else
            {
                _directtion = eDirection.eRight;
                _nStep = 0;
            }
        }
        public void NextAction()
        {
            switch (_directtion)
            {
                case eDirection.eUp:
                case eDirection.eDown:
                    _nStep++;
                    _nStep %= (_rutinSize * 2);
                    break;
                case eDirection.eRight:
                case eDirection.eLeft:
                    _nStep++;
                    _nStep %= (_rutinSize * 2);
                    break;
            }
        }
        public void MoveNext(bool bMove = true) //한방향으로이동.
        {
            switch (_directtion)
            {
                case eDirection.eUp:
                    _rectLoc.Y -= _SetpOne;
                    _nStep++;
                    _nStep %= (_rutinSize * _nActionGap);
                    break;
                case eDirection.eDown:
                    _rectLoc.Y += _SetpOne;
                    _nStep++;
                    _nStep %= (_rutinSize * _nActionGap);
                    break;
                case eDirection.eRight:
                    _rectLoc.X += _SetpOne;
                    _nStep++;
                    _nStep %= (_rutinSize * _nActionGap);
                    break;
                case eDirection.eLeft:
                    _rectLoc.X -= _SetpOne;
                    _nStep++;
                    _nStep %= (_rutinSize * _nActionGap);
                    break;
            }
        }
        public void Draw(Graphics g)
        {
            Rectangle rect = new Rectangle(0, 0, _itemSize.Width, _itemSize.Height);
            //Rectangle rect = new Rectangle(0, 0, 124, 70);
            rect.X = _itemSize.Width * (_nStep / _nActionGap);
            rect.Y = _itemSize.Height * (int)_directtion;
            GraphicsUnit srcUnit = GraphicsUnit.Pixel;
            g.DrawImage(_charImage, _rectLoc, rect, srcUnit);
        }

        public object Clone()
        {
            Character character = (Character)this.MemberwiseClone();
            return character;
        }

    }



    
}
