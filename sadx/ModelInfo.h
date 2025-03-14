#ifndef MODELINFO_H
#define MODELINFO_H

#include <cstdint>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "ninja.h"
#include "WeightInfo.h"

enum ModelFormat
{
	ModelFormat_Invalid,
	ModelFormat_Basic,
	ModelFormat_Chunk
};

class ModelInfo
{
public:
	struct Metadata
	{
		uint32_t size;
		const uint8_t* data;
	};

	explicit ModelInfo(const char* filename);
	explicit ModelInfo(const std::string& filename);
#ifdef _MSC_VER
	explicit ModelInfo(const wchar_t* filename);
	explicit ModelInfo(const std::wstring& filename);
#endif /* _MSC_VER */
	explicit ModelInfo(std::istream& stream);

	ModelFormat getformat() const;
	NJS_OBJECT* getmodel() const;
	const std::string& getauthor() const;
	const std::string& gettool() const;
	const std::string& getdescription() const;
	const uint8_t* getmetadata(uint32_t identifier, uint32_t& size);
	const std::string& getlabel(void* data);
	void* getdata(const std::string& label);
	const std::unordered_map<std::string, void *>* getlabels() const;
	const std::list<std::string>& getanimations() const;
	const std::list<std::string>& getmorphs() const;
	WeightInfo* getweightinfo();

private:
	static const uint64_t SA1MDL        = 0x4C444D314153ULL;
	static const uint64_t SA2MDL        = 0x4C444D324153ULL;
	static const uint64_t FormatMask    = 0xFFFFFFFFFFFFULL;
	static const uint8_t CurrentVersion = 3;

	static constexpr size_t headerSize = 0x10;

	ModelFormat format = ModelFormat_Invalid;
	NJS_OBJECT* model = nullptr;
	std::string author, tool, description;
	std::unordered_map<uint32_t, Metadata> metadata;
	std::unordered_map<void *, std::string> labels1;
	std::unordered_map<std::string, void *> labels2;
	std::vector<std::shared_ptr<void>> allocatedmem;
	std::unordered_set<void *> fixedpointers;
	std::unordered_map<void *, void *> reallocateddata;
	std::list<std::string> animations, morphs;
	std::vector<WeightNode> weightNodes;
	WeightInfo weightInfo{};

	enum ChunkTypes : uint32_t
	{
		ChunkTypes_Label = 0x4C42414C,
		ChunkTypes_Animation = 0x4D494E41,
		ChunkTypes_Morph = 0x46524F4D,
		ChunkTypes_Author = 0x48545541,
		ChunkTypes_Tool = 0x4C4F4F54,
		ChunkTypes_Description = 0x43534544,
		ChunkTypes_Texture = 0x584554,
		ChunkTypes_Weights = 0x54484757,
		ChunkTypes_End = 0x444E45
	};

	void fixbasicmodelpointers(NJS_MODEL_SADX* model, intptr_t base);
	static void fixchunkmodelpointers(NJS_CNK_MODEL* model, intptr_t base);
	void fixobjectpointers(NJS_OBJECT* object, intptr_t base);
	void init(std::istream& stream);
};

#endif /* MODELINFO_H */
