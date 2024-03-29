
#ifndef MEETING_SDK_LINUX_SAMPLE_ZOOMSDKAUDIORAWDATADELEGATE_H
#define MEETING_SDK_LINUX_SAMPLE_ZOOMSDKAUDIORAWDATADELEGATE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "zoom_sdk_raw_data_def.h"
#include "meeting_service_interface.h"
#include "rawdata/rawdata_audio_helper_interface.h"
#include "meeting_service_components/meeting_audio_interface.h"
#include "meeting_service_components/meeting_participants_ctrl_interface.h"
#include "../util/Log.h"

using namespace std;
using namespace ZOOMSDK;

class ZoomSDKAudioRawDataDelegate : public IZoomSDKAudioRawDataDelegate {
    string m_dir = "out";
    string m_filename = "test.pcm";
    bool m_useMixedAudio;
    IMeetingService* m_meetingService;

    void writeToFile(const string& path, AudioRawData* data);
public:
    ZoomSDKAudioRawDataDelegate(bool useMixedAudio, IMeetingService* m_meetingService);

    void setDir(const string& dir);
    void setFilename(const string& filename);

    void onMixedAudioRawDataReceived(AudioRawData* data) override;
    void onOneWayAudioRawDataReceived(AudioRawData* data, uint32_t node_id) override;
    void onShareAudioRawDataReceived(AudioRawData* data) override;
};


#endif //MEETING_SDK_LINUX_SAMPLE_ZOOMSDKAUDIORAWDATADELEGATE_H
