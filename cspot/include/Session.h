#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include <random>
#include <pb_encode.h>
#include <memory>
#include <functional>
#include <climits>
#include <algorithm>
#include "Utils.h"
#include "stdlib.h"
#include "ShannonConnection.h"
#include "LoginBlob.h"
#include "ApResolve.h"
#include "PlainConnection.h"
#include "PBUtils.h"
#include "Packet.h"
#include "keyexchange.pb.h"
#include "ConstantParameters.h"
#include "Crypto.h"
#include "authentication.pb.h"

#define SPOTIFY_VERSION 0x10800000000
#define LOGIN_REQUEST_COMMAND 0xAB
#define AUTH_SUCCESSFUL_COMMAND 0xAC
#define AUTH_DECLINED_COMMAND 0xAD

class Session
{
private:
    std::shared_ptr<PlainConnection> conn;
    std::unique_ptr<Crypto> crypto;
    std::vector<uint8_t> sendClientHelloRequest();
    void processAPHelloResponse(std::vector<uint8_t> &helloPacket);

public:
    Session();
    std::shared_ptr<ShannonConnection> shanConn;
    void connect(std::shared_ptr<PlainConnection> connection);
    void connectWithRandomAp();
    std::vector<uint8_t> authenticate(std::shared_ptr<LoginBlob> blob);
};

#endif