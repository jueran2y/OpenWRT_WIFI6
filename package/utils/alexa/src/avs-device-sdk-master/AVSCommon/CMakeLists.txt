project(AVSCommon)

find_package(CURL ${CURL_PACKAGE_CONFIG})

add_definitions("-DACSDK_LOG_MODULE=avsCommon")

add_subdirectory("AVS")
add_subdirectory("SDKInterfaces")
add_subdirectory("Utils")

add_library(AVSCommon SHARED
    AVS/src/AVSDirective.cpp
    AVS/src/AVSMessage.cpp
    AVS/src/AVSMessageHeader.cpp
    AVS/src/AbstractAVSConnectionManager.cpp
    AVS/src/BlockingPolicy.cpp
    AVS/src/ExternalMediaPlayer/AdapterUtils.cpp
    AVS/src/AlexaClientSDKInit.cpp
    AVS/src/Attachment/Attachment.cpp
    AVS/src/Attachment/AttachmentManager.cpp
    AVS/src/Attachment/AttachmentUtils.cpp
    AVS/src/Attachment/InProcessAttachment.cpp
    AVS/src/Attachment/InProcessAttachmentReader.cpp
    AVS/src/Attachment/InProcessAttachmentWriter.cpp
    AVS/src/CapabilityConfiguration.cpp
    AVS/src/CapabilityAgent.cpp
    AVS/src/DialogUXStateAggregator.cpp
    AVS/src/EventBuilder.cpp
    AVS/src/ExceptionEncounteredSender.cpp
    AVS/src/HandlerAndPolicy.cpp
    AVS/src/MessageRequest.cpp
    AVS/src/NamespaceAndName.cpp
    Utils/src/Bluetooth/SDPRecords.cpp
    Utils/src/BluetoothEventBus.cpp
    Utils/src/Configuration/ConfigurationNode.cpp
    Utils/src/DeviceInfo.cpp
    Utils/src/Executor.cpp
    Utils/src/FileUtils.cpp
    Utils/src/FormattedAudioStreamAdapter.cpp
    Utils/src/JSON/JSONGenerator.cpp
    Utils/src/JSON/JSONUtils.cpp
    Utils/src/HTTP2/HTTP2GetMimeHeadersResult.cpp
    Utils/src/HTTP2/HTTP2MimeRequestEncoder.cpp
    Utils/src/HTTP2/HTTP2MimeResponseDecoder.cpp
    Utils/src/HTTP2/HTTP2SendDataResult.cpp
    Utils/src/LibcurlUtils/CallbackData.cpp
    Utils/src/LibcurlUtils/CurlEasyHandleWrapper.cpp
    Utils/src/LibcurlUtils/CurlMultiHandleWrapper.cpp
    Utils/src/LibcurlUtils/HTTPContentFetcherFactory.cpp
    Utils/src/LibcurlUtils/HttpPost.cpp
    Utils/src/LibcurlUtils/HttpPut.cpp
    Utils/src/LibcurlUtils/HTTPResponse.cpp
    Utils/src/LibcurlUtils/LibCurlHttpContentFetcher.cpp
    Utils/src/LibcurlUtils/LibcurlHTTP2Connection.cpp
    Utils/src/LibcurlUtils/LibcurlHTTP2ConnectionFactory.cpp
    Utils/src/LibcurlUtils/LibcurlHTTP2Request.cpp
    Utils/src/LibcurlUtils/LibcurlUtils.cpp
    Utils/src/Logger/ConsoleLogger.cpp
    Utils/src/Logger/Level.cpp
    Utils/src/Logger/LogEntry.cpp
    Utils/src/Logger/LogEntryBuffer.cpp
    Utils/src/Logger/LogEntryStream.cpp
    Utils/src/Logger/Logger.cpp
    Utils/src/Logger/LoggerSinkManager.cpp
    Utils/src/Logger/LoggerUtils.cpp
    Utils/src/Logger/LogStringFormatter.cpp
    Utils/src/Logger/ModuleLogger.cpp
    Utils/src/Logger/ThreadMoniker.cpp
    Utils/src/MacAddressString.cpp
    Utils/src/Metrics.cpp
    Utils/src/Network/InternetConnectionMonitor.cpp
    Utils/src/RequiresShutdown.cpp
    Utils/src/RetryTimer.cpp
    Utils/src/SafeCTimeAccess.cpp
    Utils/src/Stopwatch.cpp
    Utils/src/Stream/StreamFunctions.cpp
    Utils/src/Stream/Streambuf.cpp
    Utils/src/StringUtils.cpp
    Utils/src/TaskThread.cpp
    Utils/src/TimePoint.cpp
    Utils/src/TimeUtils.cpp
    Utils/src/Timer.cpp
    Utils/src/UUIDGeneration.cpp)

target_include_directories(AVSCommon PUBLIC
    "${AVSCommon_SOURCE_DIR}/AVS/include"
    "${AVSCommon_SOURCE_DIR}/SDKInterfaces/include"
    "${AVSCommon_SOURCE_DIR}/Utils/include"
    "${RAPIDJSON_INCLUDE_DIR}"
    "${MultipartParser_SOURCE_DIR}"
    "${MBEDTLS_INCLUDE_DIR}"
    "${NGHTTP2_INCLUDE_DIR}"
    ${CURL_INCLUDE_DIRS})

target_link_libraries(AVSCommon
    ${CURL_LIBRARIES})

target_link_libraries(AVSCommon
    ${MBEDCRYPTO_LIBRARY})

target_link_libraries(AVSCommon
    ${MBEDTLS_LIBRARY})

target_link_libraries(AVSCommon
    ${MBEDX509_LIBRARY})

target_link_libraries(AVSCommon
    ${NGHTTP2_LIBRARY})

# install target
LIST(APPEND PATHS "${PROJECT_SOURCE_DIR}/AVS/include")
LIST(APPEND PATHS "${PROJECT_SOURCE_DIR}/SDKInterfaces/include")
LIST(APPEND PATHS "${PROJECT_SOURCE_DIR}/Utils/include")
asdk_install_multiple("${PATHS}")
