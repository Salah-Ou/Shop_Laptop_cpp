#include "utils.h"
#include <limits>
#include <cstring>

using namespace std;

void gotoxy(int x, int y) {
#ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    cout << "\033[" << y + 1 << ";" << x + 1 << "H";
#endif
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause_screen() {
#ifdef _WIN32
    system("pause");
#else
    cout << "Press Enter to continue..."; 
#endif
}

void Cleaning_Line() {
    cout << "\033[K";
}

void Sleep(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

void Beep(float frequency, float duration) {
#ifdef _WIN32
    Beep(frequency, duration);
#else
    float volume = 0.09f;
    const float sampleRate = 44100.0f;
    int numSamples = (int)(sampleRate * duration);

    AudioQueueRef queue;
    AudioStreamBasicDescription format = {};
    format.mSampleRate       = sampleRate;
    format.mFormatID         = kAudioFormatLinearPCM;
    format.mFormatFlags      = kLinearPCMFormatFlagIsSignedInteger | kLinearPCMFormatFlagIsPacked;
    format.mBitsPerChannel   = 16;
    format.mChannelsPerFrame = 1;
    format.mBytesPerFrame    = 2;
    format.mFramesPerPacket  = 1;
    format.mBytesPerPacket   = 2;

    AudioQueueNewOutput(&format, [](void*, AudioQueueRef, AudioQueueBufferRef) {},
                        nullptr, nullptr, nullptr, 0, &queue);

    AudioQueueBufferRef buffer;
    AudioQueueAllocateBuffer(queue, numSamples * 2, &buffer);
    buffer->mAudioDataByteSize = numSamples * 2;

    int16_t* data = (int16_t*)buffer->mAudioData;
    for (int i = 0; i < numSamples; i++) {
        float t    = (float)i / sampleRate;
        float fade = (i < 1000)              ? (float)i / 1000.0f :
                    (i > numSamples - 1000) ? (float)(numSamples - i) / 1000.0f : 1.0f;
        data[i] = (int16_t)(32767 * volume * fade * sin(0.9f * M_PI * frequency * t));
    }

    AudioQueueEnqueueBuffer(queue, buffer, 0, nullptr);
    AudioQueueStart(queue, nullptr);
    usleep((useconds_t)(duration * 100000));
    AudioQueueStop(queue, true);
    AudioQueueDispose(queue, true);
#endif
}

char _getch() {
#ifdef _WIN32
    return _getch();
#else
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}