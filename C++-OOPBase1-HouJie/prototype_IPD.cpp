#include<bits/stdc++.h>
using namespace std;

const int NUM_IMAGES = 2;
enum imageType
{
    A,
    B,
};
imageType input[NUM_IMAGES] =
{
    A,
    B,
};

#ifndef __IMAGE__
#define __IMAGE__

class Image
{
public:
    static Image* prototypes[10];
    static int cnt;
protected:
    virtual imageType ReturnType() = 0;
    virtual Image* Clone() = 0;
    static void AddPrototype(Image* image)
    {
        prototypes[cnt++] = image;
    }
public:
    virtual void Draw() = 0;
    static Image* FindAndClone(imageType type)
    {
        for (int i = 0; i < cnt; i++)
        {
            if (prototypes[i]->ReturnType() == type)
            {
                return prototypes[i]->Clone();
                break;
            }
        }
        cout << "nullptr" << endl;
        return nullptr;
    }
};
Image* Image::prototypes[];
int Image::cnt;

#endif


#ifndef __AIMAGE__
#define __AIMAGE__

class AImage : public Image
{
private:
    static AImage aImage;
    static int cnt;
    int id;
    AImage()
    {
        cout << "Add" << endl;
        AddPrototype(this);
    }
    AImage(int dummy)
    {
        cout << "A" << endl;
        id = cnt++;
    }
public:
    virtual imageType ReturnType()
    {
        return A;
    }
    virtual Image* Clone()
    {
        cout << "Clone" << endl;
        return new AImage(1);
    }
    virtual void Draw()
    {
        cout << "AImage::Draw: " << id << endl;
    }
};
AImage AImage::aImage;
int AImage::cnt = 1;

#endif


#ifndef __BIMAGE__
#define __BIMAGE__

class BImage : public Image
{
private:
    static BImage bImage;
    static int cnt;
    int id;
    BImage()
    {
        AddPrototype(this);
    }
    BImage(int dummy)
    {
        id = cnt++;
    }
public:
    virtual imageType ReturnType()
    {
        return B;
    }
    virtual BImage* Clone()
    {
        return new BImage(1);
    }
    virtual void Draw()
    {
        cout << "BImage::Draw: " << id << endl;
    }
};
BImage BImage::bImage;
int BImage::cnt = 1;

#endif

int main()
{
    Image* image[NUM_IMAGES];
    for (int i = 0; i < NUM_IMAGES; i++)
    {
        image[i] = Image::FindAndClone(input[i]);
    }
    for (int i = 0; i < NUM_IMAGES; i++)
    {
        image[i]->Draw();
    }
    for (int i = 0 ; i < NUM_IMAGES; i++)
    {
        delete image[i];
    }
    return 0;
}
