class Solution:
    def compress1(self, chars: List[str]) -> int:
        # i: index to read; j: index to write
        j = 0
        count = 1
        def _appendCharCount(ch, count):
            nonlocal j
            #print ('_appendCharCount, j:', j, ' i:', i, ' count:', count)
            chars[j] = ch
            j += 1
            if count > 1:
                for t in str(count):
                    chars[j] = t
                    j += 1
            
        for i, ch in enumerate(chars):
            if i == 0: continue
            if ch != chars[i-1]:
                _appendCharCount(chars[i-1], count)
                count = 1
            else:
                count += 1
        _appendCharCount(chars[i], count)
        del chars[j:]
        return len(chars)
        
    # NOTE: compare i with i+1
    def compress(self, chars: List[str]) -> int:
        j = 0
        count = 1
        
        def _appendCharCount(ch, count):
            nonlocal j
            #print ('_appendCharCount, j:', j, ' i:', i, ' count:', count)
            chars[j] = ch
            j += 1
            if count > 1:
                for t in str(count):
                    chars[j] = t
                    j += 1
                    
        for i, ch in enumerate(chars):
            if i == len(chars) -1 or ch != chars[i+1]:
                _appendCharCount(ch, count)
                count = 1
            else:
                count += 1
        del chars[j:]
        return len(chars)
            
            
            
