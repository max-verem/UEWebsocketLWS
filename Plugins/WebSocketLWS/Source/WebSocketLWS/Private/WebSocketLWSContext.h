/*
* uewebsocket - unreal engine 4 websocket plugin
*
* Copyright (C) 2017 feiwu <feixuwu@outlook.com>
* Copyright (C) 2021 Maksym Veremeyenko <verem@m1.tv>
*
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation:
*  version 2.1 of the License.
*
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
*  MA  02110-1301  USA
*/

#pragma once

#include "UObject/NoExportTypes.h"
#include "Tickable.h"
namespace libwebsockets {
    #include "libwebsockets.h"
}
#include "WebSocketLWSContext.generated.h"


class UWebSocketLWSBase;
/**
 * 
 */
UCLASS()
class UWebSocketLWSContext : public UObject, public FTickableGameObject
{
	GENERATED_BODY()
public:

	UWebSocketLWSContext();

	void CreateCtx();

	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;

	UWebSocketLWSBase* CreateInstance(const FString& uri);
	UWebSocketLWSBase* CreateInstance(const FString& uri, const TMap<FString, FString>& header);

	static int callback_echo(struct libwebsockets::lws *wsi, enum libwebsockets::lws_callback_reasons reason, void *user, void *in, size_t len);
	
private:
	struct libwebsockets::lws_context* mlwsContext;
};
