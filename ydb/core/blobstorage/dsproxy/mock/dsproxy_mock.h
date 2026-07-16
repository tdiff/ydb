#pragma once

#include "defs.h"
#include <ydb/core/base/blobstorage_common.h>
namespace NKikimr {

    namespace NFake {
        class TProxyDS;
    } // NFake

    IActor *CreateBlobStorageGroupProxyMockActor(TIntrusivePtr<NFake::TProxyDS> model);
    IActor *CreateBlobStorageGroupProxyMockActor(TGroupId groupId);

    struct TBSFailureInjectionConfig
    {
        double FailureProbability = 0.0;
        std::optional<ui64> RandomSeed = 0;
    };
    IActor *CreateBlobStorageGroupFailureInjectingActor(TActorId actorId, ui32 groupId, TBSFailureInjectionConfig config);

} // NKikimr
