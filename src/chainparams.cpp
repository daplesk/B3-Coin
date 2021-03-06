// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xb3;
        pchMessageStart[1] = 0x2e;
        pchMessageStart[2] = 0x1e;
		pchMessageStart[3] = 0xe6;
        vAlertPubKey = ParseHex("04b5ffc3286e618001604b5e16eefc30812c7d0b2dc91af9ee470c4605a9183d162c912bb437341270f00637432d2af3e7c01bcabcbdb8c085d56d97a08f355ce4");
        nDefaultPort = 5647;
        nRPCPort = 5467;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        const char* pszTimestamp = "China launches Gaofen-3 Staellite to get accurate images of earth on 11-august";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1481667355, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1481667355;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact(); // 0x1e0ffff0;
        genesis.nNonce   = 499515;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x4b0d7f133c5267d715d4d8992635a5490d1edd6b7072cce3f8fe116aba983b6a"));
        assert(genesis.hashMerkleRoot == uint256("0x4243fd570d4cb2e2930767f5bf18b2f65f1b7c4e16a392552d1efadeec00753d"));

        vSeeds.push_back(CDNSSeedData("seed001", "seed001.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed002", "seed002.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed003", "seed003.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed004", "seed004.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed005", "seed005.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed006", "seed006.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed007", "seed007.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed008", "seed008.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed009", "seed009.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed010", "seed010.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed011", "seed011.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed012", "seed012.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed013", "seed013.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed014", "seed014.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed015", "seed015.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed016", "seed016.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed017", "seed017.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed018", "seed018.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed019", "seed019.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed020", "seed020.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed021", "seed021.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed022", "seed022.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed023", "seed023.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed024", "seed024.b3nodes.net"));
        vSeeds.push_back(CDNSSeedData("seed025", "seed025.b3nodes.net"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 63); //
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 85); 
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 153);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

	//SuperBlock
        vSuperBlockPubKey = ParseHex("0432160bdb95ec14c30a3c76ed742403a34d3b57841f49caec6971eee735bcc68d35d35936c66719910b32c51db72621191437d23659785fe20ee7268e7d340522");
        nSuperBlockHeight = 107488;

        nLastPOWBlock = 500; //Bitte Main.cpp checken. Für längers POW muss ein andere Futuredrift eingerichtet werden if (GetBlockTime() > FutureDrift((int64_t)vtx[0].nTime))
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xcd;
        pchMessageStart[1] = 0xf2;
        pchMessageStart[2] = 0xc0;
        pchMessageStart[3] = 0xef;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        vAlertPubKey = ParseHex("04530bafe00460bf4f91ef8579684dafd9ef312e1c3d696a0a233c79019a11273a7419a4df97737fdab2cb01bd78fa923c136d54e71bb7ab272162a99047f11fb6");
        nDefaultPort = 30420;
        nRPCPort = 30421;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 499515;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x4b0d7f133c5267d715d4d8992635a5490d1edd6b7072cce3f8fe116aba983b6a"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        vSuperBlockPubKey = ParseHex("04e66ccd841d343c3599197e866bf2b8ab50b97ea3998d4ee6e70814713c7401b14b5bdd51a768ed54ef25699a83d3a07724b1287546211e1672b722cc83098f30");
        nSuperBlockHeight = 125;

        nLastPOWBlock = 100;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        genesis.nTime = 1481667355;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 499515;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";
        assert(hashGenesisBlock == uint256("0x4b0d7f133c5267d715d4d8992635a5490d1edd6b7072cce3f8fe116aba983b6a"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
